class Solution {
public:
    vector<int>x={-1,0,0,1};
    vector<int>y={0,1,-1,0};
    void bfs(int i, int j, vector<vector<char>>&grid){
        queue<pair<int,int>>q;
        q.push({i,j});
        while(q.size()){
            int x1 = q.front().first;
            int y1 = q.front().second;
            q.pop();
            for(int dir = 0; dir < 4; dir++){
                int newX = x1 + x[dir];
                int newY = y1 + y[dir];
                if(newX >= 0 && newY >= 0 && newX<grid.size() && newY<grid[0].size() && grid[newX][newY]=='1'){
                    q.push({newX,newY});
                    grid[newX][newY]='0';
                }
            }
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        for(int i = 0 ; i < n; i++){
            for(int j = 0 ; j < m; j++){
                if(grid[i][j]=='1'){
                    bfs(i,j,grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};

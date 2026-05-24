class Solution {
public:
    vector<int>x = {0,0,1,-1};
    vector<int>y = {-1,1,0,0};
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n ;i++){
            for(int j = 0 ; j < m; j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                }
            }
        }
        while(q.size()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i = 0 ; i < 4;i++){
                int nr = r + x[i];
                int nc = c + y[i];
                if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc]==2147483647){
                    grid[nr][nc] = grid[r][c] + 1;
                    q.push({nr,nc});
                }
            }
        }
    }
};

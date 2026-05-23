class Solution {
public:
    vector<int>x={-1,0,0,1};
    vector<int>y={0,1,-1,0};
    void dfs(int i, int j, vector<vector<char>>&grid){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]=='0'){
            return;
        }
        grid[i][j] = '0';
        for(int dir = 0; dir < 4; dir++){
            dfs(i+x[dir],j+y[dir],grid);
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        for(int i = 0 ; i < n; i++){
            for(int j = 0 ; j < m; j++){
                if(grid[i][j]=='1'){
                    dfs(i,j,grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};

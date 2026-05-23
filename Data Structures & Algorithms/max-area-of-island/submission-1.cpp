class Solution {
public:
    vector<int>x={-1,0,0,1};
    vector<int>y={0,1,-1,0};
    int dfs(int i, int j, vector<vector<int>>&grid){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]==0){
            return 0;
        }
        grid[i][j] = 0;
        int ans = 1;
        for(int dir = 0; dir < 4; dir++){
            ans+=dfs(i+x[dir],j+y[dir],grid);
        }
        return ans;

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        for(int i = 0 ; i < n; i++){
            for(int j = 0 ; j < m; j++){
                if(grid[i][j]==1){
                    ans=max(ans,dfs(i,j,grid));
                    
                }
            }
        }
        return ans; 
    }
};

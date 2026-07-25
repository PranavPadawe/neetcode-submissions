class Solution {
public:
    vector<int>x = {0,0,1,-1};
    vector<int>y = {-1,1,0,0};
    void dfs(int i, int j, vector<vector<bool>>&ocean, vector<vector<int>>&heights){
        ocean[i][j] = true;
        for(int dir = 0; dir<4; dir++){
            int nr = i + x[dir];
            int nc = j + y[dir];
            if(nr>=0 && nc>=0 && nr<heights.size() && nc<heights[0].size() && ocean[nr][nc]==false
                && heights[nr][nc]>=heights[i][j]){
                    dfs(nr,nc,ocean,heights);
                }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<bool>>act(n,vector<bool>(m,false));
        vector<vector<bool>>pac(n,vector<bool>(m,false));

        for(int i = 0;i<n;i++){
            dfs(i,0,pac,heights);
            dfs(i,m-1,act,heights);
        }
        for(int j = 0; j<m ; j++){
            dfs(0,j,pac,heights);
            dfs(n-1,j,act,heights);
        }
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(act[i][j] && pac[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;

    }
};

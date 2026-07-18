class Solution {
public:
    vector<int>x = {0,0,1,-1};
    vector<int>y = {-1,1,0,0};
    int dfs(int i, int j,int n,int m,vector<vector<int>>&matrix,vector<vector<int>>&dp,int prev){
        if(i<0 || i>=n || j<0 || j>=m || matrix[i][j]<=prev){
            return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int ans = 1;
        for(int dir=0;dir<4;dir++){
            ans = max(ans,1+dfs(i+x[dir],j+y[dir],n,m,matrix,dp,matrix[i][j]));
        }
        return dp[i][j] = ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int ans = 0;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i = 0 ;i <n;i++){
            for(int j=0;j<m;j++){
                ans = max(ans,dfs(i,j,n,m,matrix,dp,-1));
            }
        }
        return ans;
    }
};

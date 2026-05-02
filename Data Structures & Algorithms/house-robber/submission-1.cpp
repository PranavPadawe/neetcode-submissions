class Solution {
public:
    int solve(int i,int n,vector<int>&arr,vector<int>&dp){
        if(i >= n)return 0;
        if(dp[i]!=-1)return dp[i];
        return dp[i] = max(solve(i + 1,n,arr,dp),arr[i] + solve(i + 2,n,arr,dp));
    }
    int rob(vector<int>& arr) {
        int n = arr.size();
        vector<int>dp(n,-1);
        return solve(0,n,arr,dp);
    }
};

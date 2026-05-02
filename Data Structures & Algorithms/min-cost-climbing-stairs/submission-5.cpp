class Solution {
public:
    int solve(int i,int n,vector<int>&arr,vector<int>&dp){
        if(i < 0)return 0;
        if(i==0 || i==1)return dp[i] = arr[i];
        if(dp[i] != -1)return dp[i];
        int ans = min(solve(i-1,n,arr,dp),solve(i-2,n,arr,dp));
        if(i<n)ans += arr[i];
        return dp[i] = ans;
    }
    int minCostClimbingStairs(vector<int>& arr) {
        int n = arr.size();
        vector<int>dp(n + 1, -1);
        return solve(n,n,arr,dp);
    }
};

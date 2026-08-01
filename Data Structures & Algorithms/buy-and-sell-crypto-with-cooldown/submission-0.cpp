class Solution {
public:
    int solve(int i, int n, int canBuy,vector<int>&arr,vector<vector<int>>&dp){
        if(i>=n)return 0;
        if(dp[i][canBuy]!=-1)return dp[i][canBuy];
        if(canBuy){
            return dp[i][canBuy] = max(-arr[i] + solve(i+1,n,0,arr,dp),solve(i+1,n,1,arr,dp));
        }
        return dp[i][canBuy] = max(arr[i] + solve(i+2,n,1,arr,dp),solve(i+1,n,0,arr,dp));
    }
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(0,n,1,arr,dp);
    }
};

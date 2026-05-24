class Solution {
public:
    int solve(int i, int n,vector<int>&coins, int amount,vector<vector<int>>&dp){
        if(amount==0)return dp[i][amount]=0;
        if(amount<0)return 1e9;
        if(i==n)return dp[i][amount]=1e9;
        if(dp[i][amount]!=-1)return dp[i][amount];
        int mini = 1e9;
        mini = min(solve(i+1,n,coins,amount,dp),1+solve(i,n,coins,amount-coins[i],dp));
        return dp[i][amount] = mini;
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        int ans = solve(0,n,coins,amount,dp);
        if(ans>=1e9)return -1;
        return ans;
    }
};

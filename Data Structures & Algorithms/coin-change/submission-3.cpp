class Solution {
public:
    int solve(int n, vector<int>&coins, int amount,vector<int>&dp){
        if(amount < 0)return 1e9;
        if(amount == 0)return 0;
        if(dp[amount]!=-1)return dp[amount];
        int ans = 1e9;
        for(auto it:coins){
            ans = min(ans,1 + solve(n,coins,amount-it,dp));
        }
        return dp[amount] = ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int>dp(amount+1,-1);
        int ans = solve(n,coins,amount,dp);
        if(ans>=1e9)return -1;
        return ans;
    }
};

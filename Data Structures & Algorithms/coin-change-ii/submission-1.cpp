class Solution {
public:
    int solve(int i,int amount, vector<int>&coins,vector<vector<int>>&dp){
        if(i==coins.size())return amount==0;
        if(dp[i][amount]!=-1)return dp[i][amount];
        int notTake = solve(i+1,amount, coins,dp);
        int take = 0;
        if(amount >= coins[i]){
            take = solve(i,amount-coins[i],coins,dp);
        }
        return dp[i][amount] = take + notTake;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        return solve(0,amount,coins,dp);   
    }
};

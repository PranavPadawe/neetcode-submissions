class Solution {
public:
    int solve(int i, int n,vector<int>&coins, int amount){
        if(amount==0)return 0;
        if(amount<0)return 1e9;
        if(i==n)return 1e9;
        int mini = 1e9;
        mini = min(solve(i+1,n,coins,amount),1+solve(i,n,coins,amount-coins[i]));
        return mini;
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int ans = solve(0,n,coins,amount);
        if(ans>=1e9)return -1;
        return ans;
    }
};

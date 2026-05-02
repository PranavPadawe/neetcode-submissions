class Solution {
public:
    int solve(int i, int n,int canPick,vector<int>&arr,vector<vector<int>>&dp){
        if(i >= n)return 0;
        if(dp[i][canPick] != -1){
            return dp[i][canPick];
        }
        int notPick = solve(i+1,n,1,arr,dp);
        int pick = 0;
        if(canPick){
            pick = arr[i] + solve(i+1,n,0,arr,dp);
        }
        return dp[i][canPick] = max(pick,notPick);
    }
    int rob(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(0,n,1,arr,dp);
    }
};

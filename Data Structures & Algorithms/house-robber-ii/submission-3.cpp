class Solution {
public:
    int solve(int i,int start , vector<int>&arr,vector<int>&dp){
        if(i < start)return 0;
        if(i == start )return dp[i]=arr[start];
        if(dp[i]!=-1)return dp[i];
        return dp[i]=max(solve(i - 1, start ,arr,dp), arr[i] + solve(i - 2, start, arr,dp));
    }
    int rob(vector<int>& arr) {
        int n = arr.size();
        if(n==1)return arr[0];
        vector<int>dp(n,-1),dp2(n,-1);
        return max(solve(n - 1, 1, arr,dp), solve(n - 2, 0 , arr,dp2));
    }

};

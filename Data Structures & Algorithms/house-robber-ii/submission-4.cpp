class Solution {
public:
    int solve(int i,int end , vector<int>&arr,vector<int>&dp){
        if(i > end)return 0;
        if(i == end )return dp[i]=arr[end];
        if(dp[i]!=-1)return dp[i];
        return dp[i]=max(solve(i + 1, end ,arr,dp), arr[i] + solve(i + 2, end, arr,dp));
    }
    int rob(vector<int>& arr) {
        int n = arr.size();
        if(n==1)return arr[0];
        vector<int>dp(n,-1),dp2(n,-1);
        return max(solve(0, n-2, arr,dp), solve(1, n-1 , arr,dp2));
    }

};

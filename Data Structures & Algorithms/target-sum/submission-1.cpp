class Solution {
public:
    int sum;
    int solve(int i, int n,vector<int>&nums, int target,vector<vector<int>>&dp){
        if(target < -sum || target > sum)return 0;
        if(i==n){
            if(target==0)return 1;
            return 0;
        }
        if(dp[i][sum+target]!=INT_MIN)return dp[i][sum+target];
        int add = solve(i+1,n,nums,target-nums[i],dp);
        int diff = solve(i+1,n,nums,target+nums[i],dp);
        return dp[i][sum+target] = add + diff;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        sum = accumulate(nums.begin(),nums.end(),0);
        int n = nums.size();
        vector<vector<int>>dp(n + 1,vector<int>(2*sum + 1,INT_MIN));
        return solve(0,nums.size(),nums,target,dp);
    }
};

class Solution {
public:
    bool solve(int i, int n,vector<int>&nums,int sum, vector<vector<int>>&dp){
        if(sum<0)return false;
        if(sum==0)return true;
        if(i==n){
            return false;
        }
        if(dp[i][sum]!=-1)return dp[i][sum];
        return dp[i][sum] = solve(i+1,n,nums, sum,dp) || solve(i+1, n, nums, sum - nums[i],dp);
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto it: nums){
            sum += it;
        }
        vector<vector<int>>dp(nums.size(),vector<int>(sum/2 +1,-1));
        if(sum&1)return false;
        return solve(0,nums.size(),nums,sum/2,dp);
    }
};

class Solution {
public:
    int solve(int i, int n,vector<int>&nums, int target){
        if(i==n){
            if(target==0)return 1;
            return 0;
        }
        int add = solve(i+1,n,nums,target-nums[i]);
        int diff = solve(i+1,n,nums,target+nums[i]);
        return add + diff;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(0,nums.size(),nums,target);
    }
};

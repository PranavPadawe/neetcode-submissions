class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int curMax = 1, curMin = 1;
        int res = nums[0];
        for(int i=0;i<n;i++){
            int temp = curMax*nums[i];
            curMax = max({nums[i], nums[i]*curMin, nums[i]*curMax});
            curMin = min({nums[i], nums[i]*curMin, temp});
            res = max(res,curMax);
        }
        return res;
    }
};

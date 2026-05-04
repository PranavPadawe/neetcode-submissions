class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN , sum = 0;
        for(int i = 0; i < nums.size() ; i++){
            sum += nums[i];
            maxi = max(maxi, sum);
            sum = max(0, sum);
        }
        return maxi;
    }
};

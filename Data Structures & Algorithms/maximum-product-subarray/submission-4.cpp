class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int res = nums[0];
        vector<int>maxi(n),mini(n);
        maxi[0] = nums[0];
        mini[0] = nums[0];
        for(int i=1;i<n;i++){
            maxi[i] = max({nums[i],nums[i]*maxi[i-1],nums[i]*mini[i-1]});
            mini[i] = min({nums[i],nums[i]*maxi[i-1],nums[i]*mini[i-1]});
            res = max(res,maxi[i]);
        }
        return res;
    }
};

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int cur = 0;
        int maxi = 0;
        for(int i = 0 ; i < n;i++){
            maxi = max(maxi, i + nums[i]);
            if(i!=n-1 && i == cur){
                cur = maxi;
                ans++;
            }
        }
        return ans;
    }
};

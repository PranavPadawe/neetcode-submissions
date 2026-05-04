class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int x = 0;
        for(auto it: nums){
            x ^= it;
        }
        for(int i = 0 ; i <= n ; i++ ){
            x ^= i;
        }
        return x;
    }
};

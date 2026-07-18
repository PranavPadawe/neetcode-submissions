class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxi = 0;
        int n = nums.size();
        bool flag = 1;
        for(int i = 0 ; i < n;i++){
            if(i > maxi){
                flag=0;
                break;
            }
            maxi = max(maxi,i + nums[i]);
        }
        return flag;
    }
};

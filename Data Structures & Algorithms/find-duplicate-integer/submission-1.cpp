class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast){
                break;
            }
        }while(slow!=fast);
        fast = 0;
        while(fast!=slow){
            slow = nums[slow];
            fast = nums[fast];
            if(slow==fast)return slow;
        }
    }
};

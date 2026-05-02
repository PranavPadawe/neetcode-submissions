class Solution {
public:
    int minCostClimbingStairs(vector<int>& arr) {
        int n = arr.size();
        vector<int>dp(n + 1 ,0);
        int secondLast = arr[0], last = arr[1];
        for(int i = 2;i <n ; i++){
            int cur = arr[i] + min(secondLast,last);
            secondLast = last;
            last = cur;
        }
        return min(last,secondLast);
    }
};

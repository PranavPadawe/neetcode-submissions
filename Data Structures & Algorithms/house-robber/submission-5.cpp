class Solution {
public:
    int rob(vector<int>& arr) {
        int n = arr.size();
        vector<int>dp(n,0);
        if(n == 1)return arr[0];
        if(n == 2)return max(arr[0],arr[1]);
        int secondLast = arr[0], last = max(arr[0],arr[1]);
        for(int i = 2; i < n; i++){
            dp[i] = max(last, arr[i] + secondLast);
            secondLast = last;
            last = dp[i];
        }
        return dp[n-1];
    }
};

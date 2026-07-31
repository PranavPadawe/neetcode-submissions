class Solution {
public:
    int solve(int start,int end , vector<int>&arr){
        int prev1 = 0;
        int prev2 = 0;
        for(int i=start;i<=end;i++){
            int cur = max(arr[i]+prev2, prev1);
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }
    int rob(vector<int>& arr) {
        int n = arr.size();
        if(n==1)return arr[0];
        vector<int>dp(n+1,-1),dp2(n+1,-1);
        return max(solve(0,n-2, arr), solve(1, n-1 , arr));
    }

};

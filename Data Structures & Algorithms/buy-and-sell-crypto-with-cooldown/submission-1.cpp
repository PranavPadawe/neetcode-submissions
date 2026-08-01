class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        int dp1_buy = 0,dp1_sell = 0,dp2_buy = 0;
        
        for(int i=n-1;i>=0;i--){
            int cur_buy = max(dp1_buy,-arr[i]+dp1_sell);
            int cur_sell = max(dp1_sell,arr[i]+dp2_buy);
            dp2_buy = dp1_buy;
            dp1_buy = cur_buy;
            dp1_sell = cur_sell;
        }
        return dp1_buy;
    }
};

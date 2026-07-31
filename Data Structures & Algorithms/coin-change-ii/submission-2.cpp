class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,0));
        dp[n][0] = 1;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=amount;j++){
                int notTake = dp[i+1][j];
                int take = 0;
                if(j-coins[i]>=0){
                    take = dp[i][j-coins[i]];
                }
                dp[i][j] = take + notTake;
            }
        }
        return dp[0][amount];  
    }
};

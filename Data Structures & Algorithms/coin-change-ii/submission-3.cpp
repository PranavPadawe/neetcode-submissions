class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int>prev(amount+1,0);
        prev[0] = 1;
        for(int i=n-1;i>=0;i--){
            vector<int>cur(amount+1,0);
            for(int j=0;j<=amount;j++){
                int notTake = prev[j];
                int take = 0;
                if(j-coins[i]>=0){
                    take = cur[j-coins[i]];
                }
                cur[j] = take + notTake;
            }
            prev = cur;
        }
        return prev[amount];  
    }
};

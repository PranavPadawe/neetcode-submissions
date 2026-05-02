class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int maxi = 0;
        int mini = INT_MAX;
        int n = arr.size();
        for(int i=0;i<n;i++){
            maxi = max(maxi,arr[i]-mini);
            mini = min(mini,arr[i]);
        }
        return maxi;
    }
};

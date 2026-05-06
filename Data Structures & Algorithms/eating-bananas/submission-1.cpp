class Solution {
public:
    int solve(int mid, vector<int>&piles){
        int ans = 0;
        for(auto it: piles){
            ans += it/mid + (it%mid ? 1: 0);
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int l = 1, r = 1e9 + 1;
        int ans = 0;
        while( l <= r){
            int mid = (l + r) >> 1;
            if(solve(mid, piles) > h){
                l = mid + 1;
            } 
            else{
                ans = mid;
                r = mid - 1;
            }
        }
        return ans;
    }
};

class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int l = 0 , r = n - 1;
        int maxi = 0;
        while(l<r){
            int temp = min(heights[l],heights[r])*(r-l);
            maxi = max(maxi,temp);
            if(heights[l]<=heights[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return maxi;
    }
};

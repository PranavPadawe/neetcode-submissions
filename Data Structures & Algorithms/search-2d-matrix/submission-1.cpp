class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int target) {
        int n = arr.size(), m = arr[0].size();
        int l = 0, r = n*m - 1;
        while (l <= r){
            int mid = (l+r)>>1;
            int row = mid/m , col = mid%m;
            if(arr[row][col] == target)return true;
            if(arr[row][col] > target){
               r = mid - 1;
            } else {
               l = mid + 1;
            }
        }
        return false;
    }
};

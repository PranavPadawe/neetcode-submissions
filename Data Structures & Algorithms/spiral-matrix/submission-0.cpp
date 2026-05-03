class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int top = 0, bottom = n - 1, left = 0, right = m - 1;
        vector<int>ans;
        while(top<=bottom && left<=right){
            for(int j = left ; j <= right; j++){
                ans.push_back(matrix[top][j]);
            }
            top++;
            for(int i = top ; i <= bottom; i++){
                ans.push_back(matrix[i][right]);
            }
            right--;
            if(!(left <= right && top <= bottom)){
                break;
            }
            for(int j = right; j >= left ; j--){
                ans.push_back(matrix[bottom][j]);
            }
            bottom--;
            for(int i=bottom; i>=top ; i--){
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
        return ans;

    }
};

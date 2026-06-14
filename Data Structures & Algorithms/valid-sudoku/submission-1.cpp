class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>>row(10,vector<int>(10,0));
        vector<vector<int>>col(10,vector<int>(10,0));
        vector<vector<int>>box(10,vector<int>(10,0));


        for(int i = 0;i < 9;i++){
            for(int j = 0; j < 9 ; j++){
                if(board[i][j]=='.')continue;
                char num = board[i][j] - '0';
                int boxNum = (i/3)*3 + (j/3);
                if(row[i][num]==1 || col[j][num]==1 || box[boxNum][num]==1){
                    return false;
                }
                row[i][num] = 1;
                col[j][num] = 1;
                box[boxNum][num] = 1;
            }
        }
        return true;
    }
};

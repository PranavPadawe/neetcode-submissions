class Solution {
public:
    bool is(int row, int col, vector<string>board){
        int r = row, c = col;
        while(r>=0 && c>=0){
            if(board[r][c]=='Q'){
                return false;
            }
            r--;
            c--;
        }
        r = row;
        c = col;
        while(r<board.size() && c>=0){
            if(board[r][c]=='Q'){
                return false;
            }
            r++;
            c--;
        }
        r = row;
        c = col;
        while(c>=0){
            if(board[r][c]=='Q'){
                return false;
            }
            c--;
        }
        return true;
    }
    void solve(int col,vector<string>&board, vector<vector<string>>&ans){
        if(col == board.size()){
            ans.push_back(board);
            return;
        }
        for(int row = 0; row < board.size(); row++){
            if(is(row,col,board)){
                board[row][col] = 'Q';
                solve(col+1,board,ans);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n,string(n,'.'));
        solve(0,board,ans);
        return ans;
    }
};

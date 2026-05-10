class Solution {
public:
    bool dfs(int idx, int i,int j, vector<vector<char>>&board,string word){
        if(idx == word.size()){
            return true;
        }
        if(i < 0 || j < 0 || i >=board.size() || j >= board[0].size() || board[i][j]=='#' || board[i][j]!=word[idx]){
            return false;
        }
        board[i][j]='#';
        bool res = dfs(idx+1,i+1,j,board,word) + dfs(idx+1,i,j+1,board,word) + dfs(idx+1,i-1,j,board,word) + dfs(idx+1,i,j-1,board,word);
        board[i][j]=word[idx];
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = word.size(), m = board[0].size();
        for(int i = 0 ; i < n ;i++){
            for(int j = 0 ; j< m;j++){
                if(dfs(0,i, j, board, word)){
                    return true;
                }
            }
        }
        return false;
    }
};

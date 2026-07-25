class Solution {
public:
    vector<int>x = {0,0,1,-1};
    vector<int>y = {-1,1,0,0};
    void capture(int i, int j,vector<vector<char>>&board){
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]!='O'){
            return;
        }
        board[i][j]='T';
        for(int dir = 0 ; dir < 4; dir++){
            capture(i+x[dir],j+y[dir],board);
        }

    }
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        for(int i = 0; i < n ; i++){
            if(board[i][0]=='O'){
                capture(i,0,board);
            }
            if(board[i][m-1]=='O'){
                capture(i,m-1,board);
            }
        }
        for(int j = 0 ; j < m; j++){
            if(board[0][j]=='O'){
                capture(0,j,board);
            }
            if(board[n-1][j]=='O'){
                capture(n-1,j,board);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                if(board[i][j]=='T'){
                    board[i][j]='O';
                }
            }
        }
    }
};

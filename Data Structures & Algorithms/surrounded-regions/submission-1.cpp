class Solution {
public:
    vector<int>x = {0,0,1,-1};
    vector<int>y = {-1,1,0,0};
    void bfs(queue<pair<int,int>>q,vector<vector<char>>&board){
        while(q.size()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]!='O'){
                continue;
            }
            board[i][j]='T';
            for(int dir = 0 ; dir < 4; dir++){
                q.push({i+x[dir],j+y[dir]});
            }
        }
        

    }
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        queue<pair<int,int>>q;
        for(int i = 0; i < n ; i++){
            if(board[i][0]=='O'){
                q.push({i,0});
            }
            if(board[i][m-1]=='O'){
                q.push({i,m-1});
            }
        }
        for(int j = 0 ; j < m; j++){
            if(board[0][j]=='O'){
                q.push({0,j});
            }
            if(board[n-1][j]=='O'){
                q.push({n-1,j});
            }
        }
        bfs(q,board);
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

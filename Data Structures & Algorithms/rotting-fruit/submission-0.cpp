class Solution {
public:
    vector<int>x = {0,-1,1,0};
    vector<int>y = {1,0,0,-1};
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int cnt = 0;
        queue<pair<int,int>>q;
        for(int i = 0 ; i < n ;i++){
            for(int j = 0 ; j < m; j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1){
                    cnt++;
                }
            }
        }
        int ans = 0;
        while(cnt && q.size()){
            int len = q.size();
            while(len--){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                for(int i = 0 ; i < 4 ; i++ ){
                    int nr = r + x[i];
                    int nc = c + y[i];
                    if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc]==1){
                        grid[nr][nc]=2;
                        cnt--;
                        q.push({nr,nc});
                    }
                }
            }
            ans++;
        }
        return cnt > 0 ? -1 : ans;
    }
};

class Solution {
public:
    vector<int>x = {0,0,1,-1};
    vector<int>y = {-1,1,0,0};
    void bfs(queue<pair<int,int>>q, vector<vector<bool>>&ocean, vector<vector<int>>&heights){
       while(q.size()){
         int i = q.front().first;
         int j = q.front().second;
         ocean[i][j] = true;
         q.pop();
         for(int dir = 0; dir<4 ; dir++){
            int nr = i + x[dir];
            int nc = j + y[dir];
            if(nr>=0 && nc>=0 && nr<heights.size() && nc<heights[0].size() && ocean[nr][nc]==false && heights[nr][nc]>=heights[i][j]){
                q.push({nr,nc});
            }
         }
       }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        queue<pair<int,int>>pacQ,actQ;
        vector<vector<bool>>pac(n,vector<bool>(m,false));
        vector<vector<bool>>act(n,vector<bool>(m,false));

        for(int i = 0;i<n;i++){
            pacQ.push({i,0});
            actQ.push({i,m-1});
        }
        for(int j = 0; j<m ; j++){
            pacQ.push({0,j});
            actQ.push({n-1,j});
        }
        bfs(pacQ,pac,heights);
        bfs(actQ,act,heights);
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(act[i][j] && pac[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;

    }
};

class Solution {
public:
    void bfs(int node, vector<int>&vis,vector<vector<int>>&adj){
        queue<int>q;
        q.push(node);
        while(q.size()){
            int node = q.front();
            vis[node] = 1;
            q.pop();
            for(auto it:adj[node]){
                if(!vis[it]){
                    q.push(it);
                }
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        int cnt = 0;
        vector<int>vis(n,0);
        vector<vector<int>>adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                bfs(i,vis,adj);
                cnt++;
            }
        }
        return cnt;
    }
};

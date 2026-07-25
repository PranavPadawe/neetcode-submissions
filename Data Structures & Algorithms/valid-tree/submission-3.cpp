class Solution {
public:
    void dfs(int node, int par,vector<bool>&vis,vector<vector<int>>&adj,int &cnt){
        vis[node]=1;
        cnt++;
        for(auto it:adj[node]){
            if(it!=par && !vis[it]){
                dfs(it,node,vis,adj,cnt);
            }
        }
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1)return false;
        int cnt = 0;
        vector<vector<int>>adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<bool>vis(n,false);
        dfs(0,-1,vis,adj,cnt);
        return cnt == n;
    }
};

class Solution {
public:
    bool dfs(int node, vector<bool>&vis,vector<bool>&pathVis, vector<vector<int>>&adj){
        vis[node]=1;
        pathVis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(it,vis,pathVis,adj))return true;
            }
            else if(pathVis[it]){
                return true;
            }
        }
        pathVis[node] = 0;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<bool>vis(n,false),pathVis(n,false);
        vector<vector<int>>adj(n);
        for(auto it:pre){
            adj[it[0]].push_back(it[1]);
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(dfs(i,vis,pathVis,adj)){
                    return false;
                }
            }
        }
        return true;
    }
};

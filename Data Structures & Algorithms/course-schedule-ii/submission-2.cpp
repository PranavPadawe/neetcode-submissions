class Solution {
public:
    void dfs(int node, vector<int>&indegree,vector<vector<int>>&adj,vector<int>&ans,vector<int>&vis){
        ans.push_back(node);
        vis[node] = 1;
        for(auto it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0 && vis[it]==0){
                dfs(it,indegree,adj,ans,vis);
            }
        }
    }
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int>ans;
        vector<int>indegree(n);
        queue<int>q;
        vector<vector<int>>adj(n);
        vector<int>vis(n,false);
        for(auto it:pre){
            indegree[it[0]]++;
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0;i<n;i++){
            if(indegree[i]==0 && vis[i]==0){
                dfs(i,indegree,adj,ans,vis);
            }
        }
        
        if(ans.size()==n)return ans;
        return {};
    }
};

class Solution {
public:
    vector<int>indegree;
    void dfs(int node,vector<vector<int>>&adj,vector<int>&ans){
        ans.push_back(node);
        indegree[node]--;       //orelse line 26 will be called again
        for(auto it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0){
                dfs(it,adj,ans);
            }
        }
    }
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int>ans;
        indegree.resize(n,0);
        queue<int>q;
        vector<vector<int>>adj(n);
        vector<int>vis(n,false);
        for(auto it:pre){
            indegree[it[0]]++;
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                dfs(i,adj,ans);
            }
        }
        
        if(ans.size()==n)return ans;
        return {};
    }
};

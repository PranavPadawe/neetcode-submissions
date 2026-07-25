class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1)return false;
        int cnt = 0;
        vector<vector<int>>adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        queue<pair<int,int>>q;
        vector<bool>vis(n,false);
        q.push({0,-1});
        vis[0] = 1;
        while(q.size()){
            int node = q.front().first;
            int par = q.front().second;
            q.pop();
            cnt++;
            vis[node] = 1;
            for(auto it:adj[node]){
                if(it!=par && !vis[it]){
                    q.push({it,node});
                }
            }
        }
        return cnt == n;
    }
};

class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int>ans;
        vector<int>indegree(n);
        queue<int>q;
        vector<vector<int>>adj(n);
        for(auto it:pre){
            indegree[it[0]]++;
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(q.size()){
            int node = q.front();
            ans.push_back(node);
            q.pop();
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        if(ans.size()==n)return ans;
        return {};
    }
};

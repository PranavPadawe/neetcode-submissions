class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        queue<int>q;
        vector<vector<int>>adj(n);
        vector<int>indegree(n);
        for(auto it:pre){
            indegree[it[1]]++;
            adj[it[0]].push_back(it[1]);
        }
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int cnt = 0;
        while(q.size()){
            int node = q.front();
            cnt++;
            q.pop();
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        return cnt == n;
    }
};

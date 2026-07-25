class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        vector<int>dis(n+1,INT_MAX);
        dis[k]=0;
        pq.push({0,k});
        while(pq.size()){
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop(); 
            if(d > dis[node]){
                continue;
            }
            for(auto it:adj[node]){
                int u = it.first;
                int w = it.second;
                if(d + w < dis[u]){
                    dis[u] = d + w;
                    pq.push({dis[u],u});
                }
            }
        }
        int maxi = 0;
        for(int i=1;i<=n;i++){
            if(i!=k){
                maxi=max(maxi,dis[i]);
            }
        }
        if(maxi==INT_MAX)return -1;
        return maxi;
    }
};

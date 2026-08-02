class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
            vector<int>arr;
            int n = points.size();
            vector<vector<pair<int,int>>>adj(n);
            for(int i=0;i<n;i++){
                for(int j=i;j<n;j++){
                    int dis = abs(points[i][0]-points[j][0]) + abs(points[i][1] - points[j][1]);
                    adj[i].push_back({j,dis});
                    adj[j].push_back({i,dis});
                }
            }
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
            pq.push({0,0});
            set<int>vis;
            int ans = 0;
            int edges = 0;
            while(edges < n){
                int cost = pq.top().first;
                int node = pq.top().second;
                pq.pop();
                if(vis.count(node)){
                    continue;
                }
                vis.insert(node);
                ans+=cost;
                edges++;
                for(auto it:adj[node]){
                    if(!vis.count(it.first)){
                        pq.push({it.second, it.first});
                    }
                }
            }
            return ans;

    }
};

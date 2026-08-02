class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
            vector<int>arr;
            int n = points.size();
            vector<int>dis(n,INT_MAX), vis(n,0);
            dis[0]=0;
            int nodes = n;
            int ans = 0;
            while(nodes--){
                int mini = INT_MAX;
                int node = -1;
                for(int i=0;i<n;i++){
                    if(!vis[i] && dis[i]<mini){
                        mini = dis[i];
                        node = i;
                    }
                }
                vis[node] = 1;
                ans+=mini;
                for(int j=0;j<n;j++){
                    int dist = abs(points[j][0]-points[node][0]) + abs(points[j][1] - points[node][1]);
                    if(!vis[j]){
                        dis[j] = min(dis[j],dist);
                    }

                }
            }
            return ans;

    }
};

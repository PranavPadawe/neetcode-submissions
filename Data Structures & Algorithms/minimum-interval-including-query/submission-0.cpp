class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end());
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<pair<int,int>>q;
        vector<int>ans(queries.size());
        for(int i=0;i<queries.size();i++){
            q.push_back({queries[i],i});
        }
        sort(q.begin(),q.end());
        int i = 0;
        for(auto it:q){
            while(i<intervals.size() && intervals[i][0]<=it.first){
                int len = intervals[i][1] - intervals[i][0] + 1;
                pq.push({len,intervals[i][1]});
                i++;
            }
            while(pq.size() && it.first>pq.top().second){
                pq.pop();
            }
            if(pq.size()==0){
                ans[it.second] = -1;
            }
            else{
                ans[it.second] = pq.top().first;
            }
        }
        return ans;
    }
};

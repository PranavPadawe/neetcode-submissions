class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>>pq;
        for(auto it: stones){
            pq.push(it);
        }
        while(pq.size()>1){
           int x = pq.top();
           pq.pop();
           int y = pq.top();
           pq.pop();
           if(x == y){
              continue;
           }
           pq.push(abs(x-y));
        }
        if(pq.size())return pq.top();
        return 0;











    }
};
















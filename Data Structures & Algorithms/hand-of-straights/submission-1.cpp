class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0){
            return false;
        }
        map<int,int>mp;
        priority_queue<int,vector<int>, greater<int>>pq;
        for(auto it:hand){
            mp[it]++;
            pq.push(it);
        }
        while(pq.size()){
            int num = pq.top();
            if(mp[num]==0){
                pq.pop();
                continue;
            }
            for(int i=0;i<groupSize;i++){
                if(mp[num+i]==0){
                    return false;
                }
                mp[num+i]--;
            }
        }
        return true;
    }
};

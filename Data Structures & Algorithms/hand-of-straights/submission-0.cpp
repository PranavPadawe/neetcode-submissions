class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0){
            return false;
        }
        map<int,int>mp;
        for(auto it:hand){
            mp[it]++;
        }
        sort(hand.begin(),hand.end());
        for(auto it:hand){
            if(mp[it]==0)continue;
            for(int i=0;i<groupSize;i++){
                if(mp[it+i]==0){
                    return false;
                }
                mp[it+i]--;
            }
        }
        return true;
    }
};

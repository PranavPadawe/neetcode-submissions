class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        set<int>st;
        int ans = 0;
        for(auto it:nums){
            st.insert(it);
        }
        for(auto it: st){
            if(st.find(it-1)==st.end()){
                int cur = it;
                int cnt = 0;
                while(st.count(it)){
                    it++;
                    cnt++;
                }
                ans = max(ans,cnt);
            }
        }
        return ans;
    }
};

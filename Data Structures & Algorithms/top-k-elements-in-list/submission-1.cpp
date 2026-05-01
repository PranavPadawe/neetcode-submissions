class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>mp;
        vector<vector<int>>freq(nums.size() + 1);
        for(auto it:nums){
            mp[it]++;
        }
        for(auto it:mp){
            freq[it.second].push_back(it.first);
        }
        vector<int>ans;
        for(int i = nums.size(); i>=0; i--){
            for(auto it:freq[i]){
                ans.push_back(it);
                if(ans.size()==k){
                    return ans;
                }
            }
        }
        return ans;
    }
};

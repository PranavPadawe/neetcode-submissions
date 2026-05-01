class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>>mp;
        for(auto it:strs){
            vector<int>arr(26,0);
            for(auto it1: it){
                arr[it1-'a']++;
            }
            string key = to_string(arr[0]);
            for(int i=1;i<26;i++){
                key += ',' + to_string(arr[i]);
            }
            mp[key].push_back(it);
        }
        vector<vector<string>>ans;
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};

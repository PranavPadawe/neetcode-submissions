class TimeMap {
public:        
    map<string,vector<pair<int,string>>>mp;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        vector<pair<int,string>>nums = mp[key];
        int l = 0 ,r = nums.size()-1;
        string ans = "";
        while(l <= r){
            int mid = (l + r)>>1;
            if(nums[mid].first<=timestamp){
                l = mid + 1;
                ans = nums[mid].second;
            }
            else{
                r = mid - 1;
            }
        }
        return ans;
    }
};

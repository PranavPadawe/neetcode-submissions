class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int l = 0;
        int maxi = 0;
        map<char,int>mp;
        for(int r = 0;r < n; r ++){
            if(mp.find(s[r])!=mp.end()){
                l = max(mp[s[r]] + 1, l);
            }
            maxi = max(maxi, r - l + 1);
            mp[s[r]] = r;
        }
        return maxi;
    }
};

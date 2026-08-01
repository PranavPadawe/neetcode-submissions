class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char,int>mp;
        int maxiF = 0;
        int l = 0;
        int ans = 0;
        for(int r=0;r<s.length();r++){
            mp[s[r]]++;
            maxiF = max(maxiF, mp[s[r]]);
            while((r-l+1)-maxiF > k){
                mp[s[l]]--;
                l++;
            }
            ans = max(ans,r-l+1);
        }
        return ans;
    }
};

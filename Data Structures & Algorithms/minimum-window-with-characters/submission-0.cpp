class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int>want,have;
        int req = 0, got = 0;
        int left = 0;
        int start = -1;
        for(auto it:t){
            have[it]++;
        }
        int minLen = INT_MAX;
        req = have.size();
        for(int right = 0 ; right < s.length() ; right++){
            want[s[right]]++;
            if(want.count(s[right]) &&  want[s[right]]==have[s[right]]){
                got++;
            }
            while(got == req){
                if(right - left + 1 < minLen){
                    minLen = right - left + 1;
                    start = left;
                }
                want[s[left]]--;
                if(want[s[left]]<have[s[left]]){
                    got--;
                }
                left++;
            }
        }
        if(minLen == INT_MAX)return "";
        return s.substr(start, minLen);
    }
};

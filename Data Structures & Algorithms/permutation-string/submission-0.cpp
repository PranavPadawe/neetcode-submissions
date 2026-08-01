class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char,int>cnt1,cnt2;
        for(int i=0;i<s1.length();i++){
            cnt1[s1[i]]++;
            cnt2[s2[i]]++;
        }
        int matches = 0;
        for(char i ='a';i<='z';i++){
            if(cnt1[i]==cnt2[i]){
                matches++;
            }
        }
        int l = 0;
        for(int r=s1.length();r<s2.length();r++){
            if(matches==26){
                return true;
            }
            char cur = s2[r];
            cnt2[cur]++;
            if(cnt1[cur]==cnt2[cur]){
                matches++;
            }
            else if(cnt1[cur]==cnt2[cur]-1){
                matches--;
            }
            cur = s2[l];
            cnt2[cur]--;
            if(cnt1[cur]==cnt2[cur]){
                matches++;
            }
            else if(cnt1[cur]==cnt2[cur]+1){
                matches--;
            }
            l++;
        }
        return matches == 26;
    }
};

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.size() != s1.size() + s2.size())return false;
        vector<bool>prev(s2.size()+1,false);
        prev[0] = true;
        for(int i = 0 ; i <= s1.size(); i++){
            vector<bool>cur(s2.size()+1,false);
            if(i==0){
                cur = prev;
            }
            for(int j = 0; j <= s2.size(); j++){
                if(i>0 && s1[i-1]==s3[i+j-1]){
                    cur[j] = cur[j] || prev[j];
                }
                if(j>0 && s2[j-1]==s3[i+j-1]){
                    cur[j] = cur[j] || cur[j-1];
                }
            }
            prev = cur;
        }
        return prev[s2.size()];
    }
};

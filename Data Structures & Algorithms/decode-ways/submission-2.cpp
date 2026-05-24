class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        int next1 = 1;
        int next2 = 0;
        int cur = 0;
        for(int i = n - 1; i>=0 ;i--){
            cur = 0;
            if(s[i]!='0'){
                cur+=next1;
                if(i + 1 < n){
                    int num = (s[i]-'0')*10 + (s[i+1]-'0');
                    if(num>=10 && num<=26){
                        cur+=next2;
                    }
                }
            }
            next2 = next1;
            next1 = cur;
        }
        return cur;
    }
};

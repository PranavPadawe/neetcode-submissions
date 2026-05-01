class Solution {
public:
    bool check(char c){
        return(c>='A' && c<='Z' || c>='a' && c<='z' || c>='0' && c<='9');
    }
    bool isPalindrome(string s) {
        int l = 0 , r = s.length()-1;
        while(l < r){
            while(l<r && !check(s[l])){
                l++;
            }
            while(l<r && !check(s[r])){
                r--;
            }
            if(tolower(s[l])!=tolower(s[r])){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};

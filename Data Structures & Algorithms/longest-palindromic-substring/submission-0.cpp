class Solution {
public:
    int solve(int i, int j,string s){
        int n = s.length();
        while(i>=0 && j<n && s[i]==s[j]){
            i--;
            j++;
        }
        return j-i-1;
    }
    string longestPalindrome(string s) {
        int n = s.length();
        int maxi = 0;
        int l = 0 , r = 0;
        for(int i=0;i<n;i++){
            int len1 = solve(i,i,s);
            int len2 = solve(i,i+1,s);
            maxi = max({maxi,len1,len2});
            if(maxi > r - l + 1){
                l = i - (maxi-1)/2;
                r = i + (maxi)/2;
            }
        }
        cout<<l<<" "<<maxi;
        return s.substr(l,maxi);
    }
};

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            dp[i][i]=true;
        }
        int maxi = 1;
        int start = 0;
        for(int len = 2; len <=n; len++){
            for(int i = 0 ; i + len - 1 < n; i++){
                int j = i + len - 1;
                if(s[i]==s[j] && (len==2 || dp[i+1][j-1]==true)){
                    dp[i][j] = true;
                    if(len > maxi){
                        maxi = len;
                        start = i;
                    }
                }
            }
        }
        cout<<maxi << " "<<start;
        return s.substr(start, maxi);
    }
};

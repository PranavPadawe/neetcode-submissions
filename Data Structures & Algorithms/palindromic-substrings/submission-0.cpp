class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            dp[i][i]=true;
        }
        int maxi = 1;
        int ans = 0;
        for(int len = 2; len <=n; len++){
            for(int i = 0 ; i + len - 1 < n; i++){
                int j = i + len - 1;
                if(s[i]==s[j] && (len==2 || dp[i+1][j-1]==true)){
                    dp[i][j] = true;
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(dp[i][j]){
                    ans++;
                }
            }
        }
        return ans;
    }
};

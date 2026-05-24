class Solution {
public:
    int solve(int i, int n, string s,vector<int>&dp){
        if(i==n)return 1;
        if(dp[i]!=-1)return dp[i];
        if(s[i]=='0')return dp[i]=0;
        int ans = solve(i+1,n,s,dp);
        if(i+1<n){
            int num = (s[i]-'0')*10 + (s[i+1]-'0');
            if(num>=10 && num<=26) ans+=solve(i+2,n,s,dp);
        }
        return dp[i]=ans;
    }
    int numDecodings(string s) {
        int n = s.length();
        vector<int>dp(n,-1);
        return solve(0,n,s,dp);
    }
};

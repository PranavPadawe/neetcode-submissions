class Solution {
public:
    bool solve(int i,string s,vector<string>&wordDict,vector<int>&dp){
        if(i==s.length()){
            return true;
        }
        if(dp[i]!=-1)return dp[i];
        for(auto word: wordDict){
            int len = word.length();
            if(i+len<=s.length() && s.substr(i,len)==word){
                if(solve(i+len,s,wordDict,dp)){
                    return dp[i]=1;
                }
            }
        }
        return dp[i]=0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int>dp(s.length(),-1);
        return solve(0,s,wordDict,dp);
    }
};

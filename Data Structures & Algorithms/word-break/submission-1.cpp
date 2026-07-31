class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int>dp(s.length()+1,0);
        int n = s.length();
        dp[n] = 1;
        for(int i=n-1;i>=0;i--){
            for(auto word: wordDict){
            int len = word.length();
                if(i+len<=n && s.substr(i,len)==word){
                    if(dp[i+len]==1){
                        dp[i]=1;
                    }
                }
            }
        }
        return dp[0];
    }
};

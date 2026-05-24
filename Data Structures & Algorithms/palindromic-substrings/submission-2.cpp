class Solution {
public:
    int solve(int i,int j,string s){
        int ans = 0;
        int n = s.length();
        while(i>=0 && i<n && s[i]==s[j]){
            ans++;
            i--;
            j++;
        }
        return ans;
    }
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        int ans = 0;
        for(int i = 0 ; i < n; i++){
            ans+=solve(i,i,s);
            ans+=solve(i,i+1,s);
        }
        return ans;
    }
};

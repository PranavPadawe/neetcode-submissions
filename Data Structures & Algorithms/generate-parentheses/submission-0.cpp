class Solution {
public:
    void solve(int open,int close,string temp,int n,vector<string>&ans){
        if(open==n && close==n){
            ans.push_back(temp);
        }
        if(close<open){
            solve(open,close+1,temp+')',n,ans);
        }
        if(open<n){
            solve(open+1,close,temp+'(',n,ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        solve(0,0,"", n,ans);
        return ans;
    }
};

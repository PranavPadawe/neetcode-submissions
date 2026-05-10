class Solution {
public:
    bool isPalindrome(int l, int r,string s){
        while(l <= r){
            if(s[l] != s[r])return false;
            l++;
            r--;
        }
        return true;
    }
    void solve(int i, string s,vector<string> temp,vector<vector<string>>&ans){
        if(i == s.length()){
            ans.push_back(temp);
            return;
        }
        for(int j = i; j < s.length(); j++){
            if(isPalindrome(i,j,s)){
                temp.push_back(s.substr(i,j - i + 1));
                solve(j + 1, s, temp, ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        solve(0,s,{},ans);
        return ans;
    }
};

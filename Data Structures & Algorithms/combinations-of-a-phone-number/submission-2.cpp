class Solution {
public:
    void solve(int i,string s,vector<string>digitToChar, string digit,vector<string>&ans){
        if(i==digit.length()){
            ans.push_back(s);
            return;
        }
        int dig = digit[i]-'0';
        for(int j = 0 ; j < digitToChar[dig].size() ; j++){
            solve(i+1,s+digitToChar[dig][j],digitToChar, digit, ans);
        }
    }
    vector<string> letterCombinations(string digit) {
        if(digit.length()==0)return {};
        vector<string> digitToChar = {
            "", "", "abc", "def", "ghi", "jkl",
            "mno", "qprs", "tuv", "wxyz"
        };
        vector<string>ans;
        string s = "";
        solve(0,s,digitToChar,digit,ans);
        return ans;
    }
};

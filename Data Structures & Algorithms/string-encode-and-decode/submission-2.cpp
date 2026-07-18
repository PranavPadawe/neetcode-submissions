class Solution {
public:

    string encode(vector<string>& strs) {
        string s;
        for(auto it:strs){
            s+=to_string(it.length()) + "#" + it;
        }
        cout<<s<<"\n";
        return s;
    }

    vector<string> decode(string s) {
        vector<string>ans;
        string temp = "";
        int i = 0, n = s.length();
        while(i < n){
            int sz = 0;
            while(s[i]!='#'){
                sz = sz*10 + (s[i]-'0');
                i++;
            }
            i++;
            int j;
            for(j=i;j<i+sz;j++){
                temp+=s[j];
            }
            i = j;
            ans.push_back(temp);
            temp="";
        }
        return ans;
    }
};

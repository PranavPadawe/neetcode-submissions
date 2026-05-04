class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        map<char,char>mp;
        mp[')'] = '(';
        mp[']'] = '[';
        mp['}'] = '{';
        for(auto it : s){
            if(it == '(' || it == '[' || it == '{'){
                st.push(it);
            }
            else{
                if(st.size() && st.top() == mp[it]){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
        return st.size() == 0;
    }
};

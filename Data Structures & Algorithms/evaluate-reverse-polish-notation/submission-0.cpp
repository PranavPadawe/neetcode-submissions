class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(auto it: tokens){
            if(it=="+" || it=="-" || it=="*" || it=="/"){
                int one = st.top();
                st.pop();
                int two = st.top();
                st.pop();
                if(it=="+"){
                    st.push(one+two);
                }
                else if(it=="-"){
                    st.push(two-one);
                }
                else if(it=="*"){
                    st.push(one*two);
                }
                else{
                    st.push(two/one);
                }
            }else{
                st.push(stoi(it));
            }
        }
        return st.top();
    }
};

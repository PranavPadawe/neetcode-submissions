class Solution {
public:
    bool checkValidString(string s) {
        int n = s.length();
        int low = 0, high = 0;
        for(int i = 0; i < n; i++){
            if(s[i]=='('){
                low++;
                high++;
            }
            else if(s[i]==')'){
                low--;
                high--;
            }
            else{
                low--;
                high++;
            }
            low = max(0,low);
            if(high < 0)return false;

        }
        return low == 0;
    }
};

class Solution {
public:
    string multiply(string num1, string num2) {
        int n = num1.size(), m = num2.size();
        if(num1=="0" || num2=="0")return "0";
        vector<int>ans(n+m,0);
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        for(int i = 0; i < n ; i++){
            for(int j = 0; j < m; j++){
                ans[i+j] += (num1[i]-'0')*(num2[j]-'0');
                ans[i+j+1]+=ans[i+j]/10;
                ans[i+j]%=10;
            }
        }
        while(ans.back()==0){
            ans.pop_back();
        }
        string fans = "";
        for(auto it:ans){
            fans = to_string(it) + fans;
        }
        return fans;
    }
};

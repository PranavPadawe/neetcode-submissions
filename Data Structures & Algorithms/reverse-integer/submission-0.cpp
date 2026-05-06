class Solution {
public:
    int reverse(int x) {
        int mini = INT_MIN;
        int maxi = INT_MAX;
        int ans = 0;
        while(x!=0){
            int digit = x%10;
            x/=10;
            if(ans > maxi/10 || (ans == maxi/10 && digit > maxi%10)){
                return 0;
            }
            if(ans < mini/10 || (ans == mini/10 && digit < mini%10)){
                return 0;
            }
            ans = (ans*10) + digit;
        }
        return ans;
    }
};

class Solution {
public:
    long long int solve(int x,long long int ans){
        if(x == 0){
            return ans;
        }
        ans = ans*10 + (x%10);
        return solve(x/10, ans);
    }
    int reverse(int x) {
        long long int ans = solve(x,0);
        if(ans < INT_MIN || ans > INT_MAX){
            return 0;
        }
        return (int)ans;
    }
};

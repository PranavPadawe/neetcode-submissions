class Solution {
public:
    double solve(double x, int n){
        if(n==0)return 1;
        if(n%2==0)return solve(x*x,n/2);
        return x*solve(x,n-1);
    }
    double myPow(double x, int n) {
        double ans = solve(x,abs(n));
        if(n<1)return 1.0/ans;
        return ans;
    }
};

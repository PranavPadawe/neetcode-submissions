class Solution {
public:
    int sumOfSquares(int n){
        int ans = 0;
        while(n){
            int temp = n%10;
            ans += temp*temp;
            n/=10;
        }
        return ans;
    }
    bool isHappy(int n) {
        int slow = n, fast = sumOfSquares(n);
        while(slow != fast){
            slow = sumOfSquares(slow);
            fast = sumOfSquares(fast);
            fast = sumOfSquares(fast);
        }
        return fast == 1;
        //coz if fast is terminating it will have value 1.. 1.. 1..
        //if fast is not terminating it will keep having values in cycle
    }
};

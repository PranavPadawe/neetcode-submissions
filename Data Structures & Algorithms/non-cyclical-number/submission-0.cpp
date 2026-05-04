class Solution {
public:
    bool isHappy(int n) {
        set<int>s;
        while(n != 1){
            if(s.count(n))return false;
            s.insert(n);
            int ans = 0;
            while(n){
                int temp = n%10;
                ans +=(temp*temp);
                n/=10;
            }
            n = ans;
        }
        return true;
    }
};

class Solution {
public:
    int getSum(int a, int b) {
        int carry = 0, ans = 0;

        for(int i = 0 ; i < 32 ; i++){
            int ax = (a >> i)&1;
            int bx = (b >> i)&1;
            cout<<ax<<" "<<bx<<"\n";
            int cur = (ax ^ bx ^ carry);
            carry = ((ax + bx + carry)>=2) ? 1 : 0;
            if(cur){
                ans |= (1 << i);
            }
        }
        if(carry){
            ans |= (1 << 32);
        }
        return ans;
    }
};

class Solution {
public:
    int reverse(int x) {
        bool neg = false;
        long long ans = 0;
        if(x < 0) neg = true, x = -x;
        while(x > 0){
            ans = ans * 10 + x % 10;
            if(ans < 0) return 0;
            x /= 10;
        }
        if(ans > INT_MAX) return 0;
        if(neg) ans = -ans;
        return ans;
    }
};

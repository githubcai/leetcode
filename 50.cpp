class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        long long tn = n;
        if(tn == 0) return 1;
        if(x == 0) return 0;
        if(tn < 0){
            x = 1.0 / x;
            tn = -tn;
        }
        while(tn > 0){
            if(tn & 1) ans *= x;
            x *= x;
            tn /= 2;
        }
        return ans;
    }
};

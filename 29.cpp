class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 0) return INT_MAX;
        if(dividend == 0) return 0;
        long long res = exp(log(fabs(dividend)) - log(fabs(divisor)));
        if(divisor < 0) res = -res;
        if(dividend < 0) res = -res;
        if(res > INT_MAX || res < INT_MIN) return INT_MAX;
        return res;
    }
};

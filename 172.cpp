class Solution {
public:
    int trailingZeroes(int n) {
        if(n < 5) return 0;
        int ret = n / 5;
        ret += trailingZeroes(ret);
        return ret;
    }
};

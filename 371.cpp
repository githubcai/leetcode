class Solution {
public:
    int getSum(int a, int b) {
        if(b == 0) return a;
        int temp = ((a & b) << 1);
        a ^= b;
        return getSum(a, temp);
    }
};

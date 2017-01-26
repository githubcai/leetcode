class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n > 0 && 2147483648 % n == 0);
    }
};

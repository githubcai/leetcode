class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int lmt = (1 << 31), last = 0;
        for(int i = 0; i <= 31; ++i){
            int temp = (lmt >> i);
            if((temp & m) != (temp & n)) break;
            last |= temp;
        }
        return (m & last);
    }
};

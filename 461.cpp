class Solution {
public:
    int hammingDistance(int x, int y) {
        x ^= y;
        int ret = 0;
        while(x > 0){
            if(x & 1) ret += 1;
            x >>= 1;
        }
        return ret;
    }
};

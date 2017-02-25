class Solution {
public:
    int findComplement(int num) {
        int ret = 0, m = 1;
        while(num > 0){
            if((num & 1) == 0) ret += m;
            num >>= 1;
            m <<= 1;
        }
        return ret;
    }
};

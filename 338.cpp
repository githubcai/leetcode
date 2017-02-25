class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret(num + 1, 0);
        for(int i = 1; i <= num; ++i){
            ret[i] = ret[i & (~(i & (-i)))] + 1;
        }
        return ret;
    }
};

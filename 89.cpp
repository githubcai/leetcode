class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ret((1 << n), 0);
        ret[0] = 0;
        if(n < 1) return ret;
        ret[1] = 1;
        for(int i = 1; i < n; ++i){
            int leng = (1 << i);
            for(int j = 0; j < leng; ++j) ret[leng + j] = ret[leng - j - 1] + leng;
        }
        return ret;
    }
};

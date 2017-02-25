class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int size = A.size(), res = 0;
        if(size < 3) return 0;
        vector<unordered_map<long long, int>> ref(size);
        ref[1][(long long)A[1] - (long long)A[0]] = 1;
        for(int i = 2; i < size; ++i){
            for(int j = 0; j < i; ++j){
                long long diff = (long long)A[i] - (long long)A[j];
                int temp = (ref[j].count(diff) == 1 ? ref[j][diff] : 0);
                res += temp;
                ref[i][diff] += temp + 1;
            }
        }
        return res;
    }
};

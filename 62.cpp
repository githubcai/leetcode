class Solution {
public:
    int uniquePaths(int m, int n) {
        int lmt = n + m - 2;
        int C[lmt + 1] = {0};
        C[0] = 1;
        for(int i = 1; i <= lmt; ++i){
            for(int j = lmt + 1; j > 0; --j){
                C[j] += C[j - 1];
            }
        }
        return C[m - 1];
    }
};

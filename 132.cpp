class Solution {
public:
    int minCut(string s) {
        int size = s.size();
        if(size == 0) return 0;
        bool flag[size][size];
        int dp[size];
        memset(flag, 0, sizeof(flag));
        for(int i = size - 1; i >= 0; --i){
            dp[i] = size - i;
            for(int j = i; j < size; ++j){
                if(s[i] == s[j] && (i + 2 >= j || flag[i + 1][j - 1])){
                    flag[i][j] = true;
                    if(j == size - 1){
                        dp[i] = 0;
                    }else{
                        dp[i] = min(dp[i], 1 + dp[j + 1]);
                    }
                }
            }
        }
        return dp[0];
    }
};

class Solution {
public:
    int integerBreak(int n) {
        if(n < 3) return 1;
        int dp[n + 1];
        memset(dp, 0, sizeof(dp));
        dp[1] = dp[2] = 1;
        for(int i = 3; i <= n; ++i){
            for(int j = 1; j < i; ++j){
                dp[i] = max(max(j * dp[i - j], j * (i - j)), dp[i]);
            }
        }
        return dp[n];
    }
};

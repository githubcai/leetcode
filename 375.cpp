class Solution {
    int dp[300][300], INF = 1 << 30;
public:
    int getMoneyAmount(int n) {
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= n; ++i){
            for(int j = i + 1; j <= n; ++j){
                dp[i][j] = dp[j][i] = INF;
            }
        }
        for(int i = 1; i < n; ++i){
            for(int j = 1; i + j <= n; ++j){
                dp[j][i + j] = min(dp[j][i + j], j + dp[j + 1][i + j]);
                dp[j][i + j] = min(dp[j][i + j], i + j + dp[j][i + j - 1]);
                for(int k = j + 1; k < i + j; ++k){
                    dp[j][i + j] = min(dp[j][i + j], max(dp[j][k - 1], dp[k + 1][i + j]) + k);
                }
            }
        }
        return dp[1][n];
    }
};

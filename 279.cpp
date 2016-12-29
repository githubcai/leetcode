class Solution {
    int INF = 1 << 30;
public:
    int numSquares(int n) {
        int dp[n + 1] = {0};
        for(int i = 1; i <= n; ++i) dp[i] = INF;
        for(int i = 1; i * i <= n; ++i){
            for(int j = i * i; j <= n; j += 1){
                if(dp[j - i * i] != INF){
                    dp[j] = min(dp[j], dp[j - i * i] + 1);
                }
            }
        }
        return dp[n];
    }
};

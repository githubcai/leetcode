class Solution {
public:
    bool isMatch(string s, string p) {
        int n = p.size(), m = s.size();
        int dp[n + 1][m + 1];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = true;
        for(int i = 1; i <= n; ++i){
            if(p[i - 1] == '*') dp[i][0] = dp[i - 1][0];
        }
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                if(p[i - 1] == '?' || p[i - 1] == s[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1];
                }else if(p[i - 1] == '*'){
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
            }
        }
        return dp[n][m];
    }
};

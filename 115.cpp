class Solution {
public:
    int numDistinct(string s, string t) {
        int slen = s.size(), tlen = t.size();
        int dp[tlen + 1][slen + 1];
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i <= slen; ++i) dp[0][i] = 1;
        for(int i = 0; i < tlen; ++i){
            for(int j = 0; j < slen; ++j){
                if(t[i] == s[j]){
                    dp[i + 1][j + 1] = dp[i][j] + dp[i + 1][j];
                }else{
                    dp[i + 1][j + 1] = dp[i + 1][j];
                }
            }
        }
        return dp[tlen][slen];
    }
};

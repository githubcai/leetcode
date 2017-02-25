class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()) return false;
        int dp[s1.size() + 1][s2.size() + 1];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = true;
        for(int i = 0; i < s1.size(); ++i){
            if(s1[i] == s3[i]){
                dp[i + 1][0] = true;
            }else{
                break;
            }
        }
        for(int i = 0; i < s2.size(); ++i){
            if(s2[i] == s3[i]){
                dp[0][i + 1] = true;
            }else{
                break;
            }
        }
        for(int i = 1; i <= s1.size(); ++i){
            for(int j = 1; j <= s2.size(); ++j){
                int l = i + j - 1;
                if(s3[l] != s1[i - 1] && s3[l] != s2[j - 1]) continue;
                if(s1[i - 1] != s3[l]){
                    dp[i][j] = dp[i][j - 1];
                }else if(s2[j - 1] != s3[l]){
                    dp[i][j] = dp[i - 1][j];
                }else{
                    dp[i][j] = (dp[i][j - 1] || dp[i - 1][j]);
                }
            }
        }
        return dp[s1.size()][s2.size()];
    }
};

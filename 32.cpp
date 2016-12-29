class Solution {
public:
    int longestValidParentheses(string s) {
        int dp[s.size() + 1], ret = 0;
        memset(dp, 0, sizeof(dp));
        for(int i = 2; i <= s.size(); ++i){
            if(s[i - 1] == ')'){
                if(s[i - 2] == '('){
                    dp[i] = dp[i - 2] + 2;
                }else{
                    if(s[i - 2 - dp[i - 1]] == '('){
                        dp[i] = dp[i - 1] + 2;
                        int temp = i - dp[i];
                        while(temp > 0 && dp[temp] != 0){
                            dp[i] += dp[temp];
                            temp = i - dp[i];
                        }
                    }
                }
            }
            if(ret < dp[i]) ret = dp[i];
        }
        return ret;
    }
};

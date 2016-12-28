class Solution {
public:
    int numDecodings(string s) {
        if(s.size() == 0) return 0;
        if(s.size() == 1){
            if(s[0] == '0') return 0;
            return 1;
        }
        int dp[s.size() + 1];
        dp[0] = 0, dp[1] = 1;
        if(s[0] == '0') return 0;
        for(int i = 2; i <= s.size(); ++i){
            int temp = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
            if(temp == 0) return 0;
            if(temp <= 26){
                if(s[i - 1] != '0'){
                    dp[i] = max(dp[i - 2] + 1, dp[i - 1] + 1);
                }else{
                    dp[i] = dp[i - 2] + 1;
                }
            }else{
                if(s[i - 1] == '0') return 0;
                dp[i] = dp[i - 1];
            }
        }
        return dp[s.size()];
    }
};

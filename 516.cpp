class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int size = s.size();
        if(size <= 1) return size;
        vector<vector<int>> dp(size, vector<int>(size, 0));
        for(int i = 0; i < size; ++i) dp[i][i] = 1;
        for(int i = 1; i < size; ++i){
            for(int j = 0; i + j < size; ++j){
                int ind, temp = -1;
                for(ind = j; ind < i + j; ++ind){
                    if(s[ind] == s[i + j]){
                        temp = dp[ind + 1][i + j - 1] + 2;
                        break;
                    }
                }
                dp[j][i + j] = max(dp[j][i + j - 1], temp);
            }
        }
        return dp[0][size - 1];
    }
};

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int dp[m + 1][n + 1];
        vector<int> zeros, ones;
        for(int i = 0; i < strs.size(); ++i){
            int one = 0, zero = 0;
            for(int j = 0; j < strs[i].size(); ++j){
                if(strs[i][j] == '1'){
                    one += 1;
                }else{
                    zero += 1;
                }
            }
            zeros.push_back(zero);
            ones.push_back(one);
        }
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < strs.size(); ++i){
            for(int j = m; j >= zeros[i]; --j){
                for(int k = n; k >= ones[i]; --k){
                    dp[j][k] = max(dp[j][k], dp[j - zeros[i]][k - ones[i]] + 1);
                }
            }
        }
        return dp[m][n];
    }
};

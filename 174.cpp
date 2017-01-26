class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if(dungeon.size() == 0) return 0;
        int m = dungeon.size(), n = dungeon[0].size();
        int dp[n];
        dp[n - 1] = 1 - dungeon[m - 1][n - 1];
        if(dp[n - 1] < 1) dp[n - 1] = 1;
        for(int i = n - 2; i >=0; --i){
            dp[i] = dp[i + 1] - dungeon[m - 1][i];
            if(dp[i] < 1) dp[i] = 1;
        }
        for(int i = m - 2; i >= 0; --i){
            dp[n - 1] = dp[n - 1] - dungeon[i][n - 1];
            if(dp[n - 1] < 1) dp[n - 1] = 1;
            for(int j = n - 2; j >= 0; --j){
                dp[j] = min(dp[j], dp[j + 1]) - dungeon[i][j];
                if(dp[j] < 1) dp[j] = 1;
            }
        }
        return dp[0];
    }
};

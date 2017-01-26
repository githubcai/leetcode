class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.size() == 0) return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        int dp[n] = {0};
        dp[0] = 1;
        for(int i = 0; i < m; ++i){
            if(obstacleGrid[i][0] == 1) dp[0] = 0;
            for(int j = 1; j < n; ++j){
                if(obstacleGrid[i][j] == 0){
                    dp[j] += dp[j - 1];
                }else{
                    dp[j] = 0;
                }
            }
        }
        return dp[n - 1];
    }
};

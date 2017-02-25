class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int rNum = triangle.size();
        if(rNum == 0) return 0;
        int dp[triangle.size()];
        for(int i = 0; i < rNum; ++i) dp[i] = triangle[rNum - 1][i];
        for(int i = rNum - 1; i >= 0; --i){
            for(int j = 0; j < i; ++j){
                dp[j] = min(dp[j], dp[j + 1]) + triangle[i - 1][j];
            }
        }
        return dp[0];
    }
};

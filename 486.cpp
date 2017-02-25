class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int size = nums.size();
        if(size < 3) return true;
        vector<int> sum(size + 1, 0);
        for(int i = 1; i <= size; ++i) sum[i] = sum[i - 1] + nums[i - 1];
        vector<vector<int>> dp(size, vector<int>(size, 0));
        for(int i = 0; i < size; ++i) dp[i][i] = nums[i];
        for(int i = 1; i <= size; ++i){
            for(int j = 0; j + i <= size; ++j){
                if(i == 1){
                    dp[j][j + i - 1] = max(nums[j], nums[j + i - 1]);
                }else{
                    int temp = sum[j + i] - sum[j];
                    dp[j][j + i - 1] = max(temp - dp[j + 1][j + i - 1] + nums[j], temp - dp[j][j + i - 2] + nums[j + i - 1]);
                }
            }
        }
        if(2 * dp[0][size - 1] >= sum[size]) return true;
        return false;
    }
};

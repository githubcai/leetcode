class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int size = nums.size();
        if(size == 0) return 0;
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(size, vector<int>(size, 0));
        for(int i = 0; i < size; ++i) dp[i][i] = nums[i] * nums[i + 1] * nums[i + 2];
        for(int i = 1; i < size; ++i){
            for(int j = 0; i + j < size; ++j){
                dp[j][i + j] = max(nums[j] * nums[j + 1] * nums[i + j + 2] + dp[j + 1][i + j], nums[j] * nums[i + j + 1] * nums[i + j + 2] + dp[j][i + j - 1]);
                for(int k = j + 1; k < i + j; ++k){
                    dp[j][i + j] = max(dp[j][i + j], nums[j] * nums[k + 1] * nums[i + j + 2] + dp[j][k - 1] + dp[k + 1][i + j]);
                }
            }
        }
        return dp[0][size - 1];
    }
};

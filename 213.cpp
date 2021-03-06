class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        int dp[nums.size() + 1];
        dp[0] = 0, dp[1] = nums[0];
        for(int i = 2; i < nums.size(); ++i){
            dp[i] = max(dp[i - 2] + nums[i - 1], dp[i - 1]);
        }
        int ret = dp[nums.size() - 1];
        dp[1] = 0;
        for(int i = 2; i <= nums.size(); ++i){
            dp[i] = max(dp[i - 2] + nums[i - 1], dp[i - 1]);
        }
        ret = max(ret, dp[nums.size()]);
        return ret;
    }
};

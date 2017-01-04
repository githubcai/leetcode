class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int dp[nums.size()], ret = nums[0];
        memset(dp, 0, sizeof(dp));
        dp[0] = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
            if(ret < dp[i]) ret = dp[i];
        }
        return ret;
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size(), ans = 1;
        if(size < 2) return size;
        vector<int> dp(size, 1);
        dp[0] = 1;
        for(int i = 1; i < size; ++i){
            for(int j = 0; j < i; ++j){
                if(nums[i] > nums[j] && dp[i] < dp[j] + 1) dp[i] = dp[j] + 1;
            }
            if(ans < dp[i]) ans = dp[i];
        }
        return ans;
    }
};

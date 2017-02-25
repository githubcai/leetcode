class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        bool flag = false;
        for(int i = 0; i < nums.size(); ++i) sum += nums[i];
        if(sum % 2 == 1){
            return false;
        }else{
            sum /= 2;
            vector<bool> dp(sum + 1, false);
            dp[0] = true;
            for(int i = 0; i < nums.size(); ++i){
                if(sum >= nums[i] && dp[sum - nums[i]]){
                    flag = true;
                    break;
                }
                for(int j = sum - 1; j >= nums[i]; --j){
                    if(dp[j - nums[i]]) dp[j] = true;
                }
            }
        }
        return flag;
    }
};

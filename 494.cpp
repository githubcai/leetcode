class Solution {
    int ret;
    void dfs(const vector<int> &nums, int ind, int S, int sum){
        if(ind == nums.size()){
            if(sum == S) ret += 1;
            return;
        }
        dfs(nums, ind + 1, S, sum + nums[ind]);
        dfs(nums, ind + 1, S, sum - nums[ind]);
    }
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        ret = 0;
        dfs(nums, 0, S, 0);
        return ret;
    }
};

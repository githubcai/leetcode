class NumArray {
    vector<int> dp;
    int size;
public:
    NumArray(vector<int> nums) {
        size = nums.size();
        if(size != 0){
            dp.resize(size, 0);
            dp[0] = nums[0];
            for(int i = 1; i < size; ++i) dp[i] = dp[i - 1] + nums[i];
        }
    }
    
    int sumRange(int i, int j) {
        if(i == 0) return dp[j];
        return dp[j] - dp[i - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mxdp[nums.size()], mndp[nums.size()], ret = nums[0];
        mxdp[0] = mndp[0] = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            int temp = mxdp[i - 1] * nums[i];
            if(temp >= 0){
                if(nums[i] < 0){
                    mxdp[i] = max(nums[i], mndp[i - 1] * nums[i]);
                    mndp[i] = min(nums[i], temp);
                }else{
                    mxdp[i] = max(nums[i], temp);
                    mndp[i] = min(nums[i], mndp[i - 1] * nums[i]);
                }
            }else{
                if(nums[i] < 0){
                    mxdp[i] = max(nums[i], mndp[i - 1] * nums[i]);
                    mndp[i] = min(nums[i], temp);
                }else{
                    mxdp[i] = max(nums[i], temp);
                    mndp[i] = min(nums[i], mndp[i - 1] * nums[i]);
                }
            }
            if(ret < mxdp[i]) ret = mxdp[i];
        }
        return ret;
    }
};

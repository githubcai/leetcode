class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int ret = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] != 0) nums[ret++] = nums[i];
        }
        for(int i = ret; i < nums.size(); ++i) nums[i] = 0;
    }
};

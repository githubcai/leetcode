class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ret = 0, size = nums.size(), cnt = 0;
        for(int i = 0; i < size; ++i){
            if(nums[i] == 1){
                cnt += 1;
                if(cnt > ret) ret = cnt;
            }else{
                cnt = 0;
            }
        }
        return ret;
    }
};

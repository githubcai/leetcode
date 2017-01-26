class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int nl = nums.size();
        for(int i = 0; i < nl; ++i){
            while(nums[i] != i + 1){
                if(nums[i] <= 0 || nums[i] > nl || nums[i] == nums[nums[i] - 1]) break;;
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for(int i = 0; i < nl; ++i){
            if(i + 1 != nums[i]) return i + 1;
        }
        return nl + 1;
    }
};

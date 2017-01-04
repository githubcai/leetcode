class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() <= 1) return;
        int index = 0;
        for(int i = nums.size() - 1; i > 0; --i){
            if(nums[i - 1] < nums[i]){
                index = i;
                break;
            }
        }
        if(index == 0){
            reverse(nums.begin(), nums.end());
            return;
        }
        int l = index;
        for(int i = index + 1; i < nums.size(); ++i){
            if(nums[i] > nums[index - 1]) l = i;
        }
        swap(nums[index - 1], nums[l]);
        reverse(nums.begin() + index, nums.end());
    }
};

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i = 0; i < nums.size(); ++i){
            while(nums[i] != i + 1){
                if(nums[i] == nums[nums[i] - 1]) break;
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for(int i = 0; i < nums.size(); ++i){
            if(i + 1 != nums[i]) return nums[i];
        }
        return -1;
    }
};

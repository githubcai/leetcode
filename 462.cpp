class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1, ret = 0;
        while(left < right){
            ret += nums[right] - nums[left];
            left += 1;
            right -= 1;
        }
        return ret;
    }
};

class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        int left = 0, right = nums.size() - 1, ans = (nums[left] < nums[right] ? nums[left] : nums[right]);
        while(left <= right){
            int mid = (left + right) / 2;
            if(nums[mid] > nums[right]){
                left = mid + 1;
            }else{
                if(ans > nums[mid]) ans = nums[mid];
                right = mid - 1;
            }
        }
        return ans;
    }
};

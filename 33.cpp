class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while(left <= right){
            int mid = (left + right) / 2;
            if(target == nums[mid]) return mid;
            if(target > nums[mid]){
                if(nums[mid] >= nums[left]){
                    left = mid + 1;
                }else{
                    if(target <= nums[right]){
                        left = mid + 1;
                    }else{
                        right = mid - 1;
                    }
                }
            }else{
                if(nums[mid] <= nums[right]){
                    right = mid - 1;
                }else{
                    if(target < nums[left]){
                        left = mid + 1;
                    }else{
                        right = mid - 1;
                    }
                }
            }
        }
        return -1;
    }
};

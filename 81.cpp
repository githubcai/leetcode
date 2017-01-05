class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while(left <= right){
            int mid = (left + right) / 2;
            if(nums[mid] == target) return true;
            if(nums[left] == nums[mid] && nums[right] == nums[mid]){
                left += 1;
                continue;
            }
            if(target < nums[mid]){
                if(nums[mid] <= nums[right]){
                    right = mid - 1;
                }else{
                    if(nums[left] == target) return true;
                    if(nums[left] < target){
                        right = mid - 1;
                    }else{
                        left = mid + 1;
                    }
                }
            }else{
                if(nums[mid] >= nums[left]){
                    left = mid + 1;
                }else if(nums[mid] < nums[left]){
                    if(nums[right] == target) return true;
                    if(nums[right] > target){
                        left = mid + 1;
                    }else{
                        right = mid - 1;
                    }
                }
            }
        }
        return false;
    }
};

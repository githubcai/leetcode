class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, ans = -1;
        vector<int> ret;
        while(left <= right){
            if(nums[right] < target) break;
            int mid = (left + right) / 2;
            if(nums[mid] > target){
                right = mid - 1;
            }else if(nums[mid] == target){
                if(ans == - 1 || mid < ans) ans = mid;
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        ret.push_back(ans);
        left = 0, right = nums.size() - 1, ans = -1;
        while(left <= right){
            if(nums[left] > target) break;
            int mid = (left + right) / 2;
            if(nums[mid] > target){
                right = mid - 1;
            }else if(nums[mid] == target){
                if(ans == - 1 || mid > ans) ans = mid;
                left = mid + 1;
            }else{
                left = mid + 1;
            }
        }
        ret.push_back(ans);
        return ret;
    }
};

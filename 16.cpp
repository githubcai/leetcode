class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closest = 1 << 30, ret;
        for(int i = 0; i < nums.size(); ++i){
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            int left = i + 1, right = nums.size() - 1;
            while(left < right){
                int temp = nums[i] + nums[left] + nums[right];
                if(temp == target) return temp;
                int t = abs(temp - target);
                if(t < closest) closest = t, ret = temp;
                if(temp > target){
                    right -= 1;
                    while(left < right && nums[right] == nums[right + 1]) right -= 1;
                }else{
                    left += 1;
                    while(left < right && nums[left] == nums[left - 1]) left += 1;
                }
            }
        }
        return ret;
    }
};

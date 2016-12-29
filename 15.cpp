class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        for(int i = 0; i < nums.size(); ++i){
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            int left = i + 1, right = nums.size() - 1;
            while(left < right){
                int temp = nums[i] + nums[left] + nums[right];
                if(temp < 0){
                    left += 1;
                    while(left < right && nums[left] == nums[left - 1]) left += 1;
                }else if(temp > 0){
                    right -= 1;
                    while(left < right && nums[right] == nums[right + 1]) right -= 1;
                }else{
                    vector<int> t;
                    t.push_back(nums[i]);
                    t.push_back(nums[left]);
                    t.push_back(nums[right]);
                    ret.push_back(t);
                    left += 1;
                    while(left < right && nums[left] == nums[left - 1]) left += 1;
                    right -= 1;
                    while(left < right && nums[right] == nums[right + 1]) right -= 1;
                }
            }
        }
        return ret;
    }
};

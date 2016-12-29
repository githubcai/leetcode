class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); ++i){
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            for(int j = i + 1; j < nums.size(); ++j){
                if(j > i + 1 && nums[j] == nums[j - 1]) continue;
                int left = j + 1, right = nums.size() - 1;
                while(left < right){
                    int temp = nums[i] + nums[j] + nums[left] + nums[right];
                    if(temp < target){
                        left += 1;
                        while(left < right && nums[left] == nums[left - 1]) left += 1;
                    }else if(temp > target){
                        right -= 1;
                        while(left < right && nums[right] == nums[right + 1]) right -= 1;
                    }else{
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[left]);
                        temp.push_back(nums[right]);
                        ret.push_back(temp);
                        left += 1;
                        while(left < right && nums[left] == nums[left - 1]) left += 1;
                        right -= 1;
                        while(left < right && nums[right] == nums[right + 1]) right -= 1;
                    }
                }
            }
        }
        return ret;
    }
};

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ret;
        ret.push_back(vector<int>());
        if(nums.size() == 0) return ret;
        if(nums.size() == 1){
            ret.push_back(vector<int>(1, nums[0]));
            return ret;
        }
        sort(nums.begin(), nums.end());
        ret.push_back(vector<int>(1, nums[0]));
        int left, right = 1;
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] == nums[i - 1]){
                left = right;
            }else{
                left = 0;
            }
            right = ret.size();
            for(int j = left; j < right; ++j){
                vector<int> temp = ret[j];
                temp.push_back(nums[i]);
                ret.push_back(temp);
            }
        }
        return ret;
    }
};

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, bool> flag;
        for(int i = 0; i < nums.size(); ++i){
            if(flag[nums[i]]) return true;
            flag[nums[i]] = true;
        }
        return false;
    }
};

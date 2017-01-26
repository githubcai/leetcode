class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> ref;
        for(int i = 0; i < nums.size(); ++i){
            if(ref[nums[i]] != 0){
                if(i - ref[nums[i]] < k) return true;
            }
            ref[nums[i]] = i + 1;
        }
        return false;
    }
};

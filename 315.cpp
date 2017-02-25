class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int size = nums.size();
        vector<int> ret(size, 0), tNums;
        for(int i = size - 1; i >= 0; --i){
            int ind;
            for(ind = 0; ind < tNums.size(); ++ind){
                if(nums[i] > tNums[ind]) break;
            }
            ret[i] = tNums.size() - ind;
            tNums.insert(tNums.begin() + ind, nums[i]);
        }
        return ret;
    }
};

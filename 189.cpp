class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size() == 0) return;
        vector<int> temp;
        int nl = nums.size();
        copy(nums.begin(), nums.end(), back_inserter(temp));
        for(int i = 0; i < nums.size(); ++i){
            temp.push_back(nums[i]);
        }
        k = nums.size() - k % nums.size();
        nums.clear();
        for(int i = 0; i < nl; ++i){
            nums.push_back(temp[i + k]);
        }
    }
};

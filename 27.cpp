class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0) return 0;
        sort(nums.begin(), nums.end());
        int ret = nums.size();
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] < val) continue;
            if(nums[i] > val) return nums.size();
            ret = i++;
            while(i < nums.size() && nums[i] == val) i += 1;
            while(i < nums.size()) nums[ret++] = nums[i++];
        }
        return ret;
    }
};

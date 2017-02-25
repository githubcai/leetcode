class Solution {
    unordered_map<int, int> ref;
    vector<int> nums;
public:
    Solution(vector<int> nums) {
        this->nums = nums;
        for(int i = 0; i < nums.size(); ++i) ref[nums[i]] += 1;
    }
    
    int pick(int target) {
        int size = ref[target];
        int des = rand() % size, cnt = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(target == nums[i]){
                if(cnt == des) return i;
                cnt += 1;
            }
        }
        return -1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */

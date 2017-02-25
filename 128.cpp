class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> res;
        for(int i = 0; i < nums.size(); ++i){
            if(res.find(nums[i]) == res.end()){
                int temp = 0, left = 0, right = 0;
                auto iter = res.find(nums[i] - 1);
                if(iter != res.end()) temp += iter->second, left = iter->second;
                iter = res.find(nums[i] + 1);
                if(iter != res.end()) temp += iter->second, right = iter->second;
                res[nums[i]] = temp + 1;
                if(left != 0) res[nums[i] - left] = res[nums[i]];
                if(right != 0) res[nums[i] + right] = res[nums[i]];
            }
        }
        int ret = 0;
        for(auto iter = res.begin(); iter != res.end(); ++iter){
            if(iter->second > ret) ret = iter->second;
        }
        return ret;
    }
};

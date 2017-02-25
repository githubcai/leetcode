class Solution {
public:
    int thirdMax(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        set<int> store;
        for(int i = 0; i < nums.size(); ++i) store.insert(nums[i]);
        vector<int> vec;
        for(auto iter = store.begin(); iter != store.end(); ++iter) vec.push_back(*iter);
        sort(vec.begin(), vec.end(), greater<int>());
        if(vec.size() < 3) return vec[0];
        return vec[2];
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int ret = 0, flag = 0;
        for(int i = 31; i >= 0; --i){
            flag |= (1 << i);
            set<int> store;
            for(int j = 0; j < nums.size(); ++j) store.insert(nums[j] & flag);
            int temp = (ret | (1 << i));
            for(auto j : store){
                if(store.find(j ^ temp) != store.end()){
                    ret = temp;
                    break;
                }
            }
        }
        return ret;
    }
};

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int r = 0;
        for(int i = 0; i < nums.size(); ++i) r ^= nums[i];
        int flag = (r & (-r));
        vector<int> ret(2, 0);
        for(int i = 0; i < nums.size(); ++i){
            if((flag & nums[i]) == 0){
                ret[0] ^= nums[i];
            }else{
                ret[1] ^= nums[i];
            }
        }
        return ret;
    }
};

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> stk;
        int size = nums.size();
        vector<int> ret(size, -1);
        for(int k = 0; k < 2; ++k){
            for(int i = 0; i < size; ++i){
                while(!stk.empty() && nums[i] > nums[stk.top()]){
                    ret[stk.top()] = nums[i];
                    stk.pop();
                }
                stk.push(i);
            }
        }
        return ret;
    }
};

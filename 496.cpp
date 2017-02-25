class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        unordered_map<int, int> ref;
        stack<int> stk;
        for(int num : nums){
            if(stk.empty()){
                stk.push(num);
            }else{
                while(!stk.empty() && stk.top() < num){
                    ref[stk.top()] = num;
                    stk.pop();
                }
                stk.push(num);
            }
        }
        while(!stk.empty()){
            ref[stk.top()] = -1;
            stk.pop();
        }
        vector<int> ret;
        for(int num : findNums){
            ret.push_back(ref[num]);
        }
        return ret;
    }
};

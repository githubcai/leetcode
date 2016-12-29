class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if(nums.size() < 3) return false;
        stack<vector<int>> stk;
        vector<int> temp;
        temp.push_back(nums[0]);
        temp.push_back(0);
        temp.push_back(1);
        temp.push_back(1);
        stk.push(temp);
        while(!stk.empty()){
            temp = stk.top();
            stk.pop();
            int cnt = temp[2];
            for(int i = temp[3]; i < nums.size(); ++i){
                if(cnt == 1){
                    if(nums[i] > temp[0]){
                        temp[cnt++] = nums[i];
                    }else if(nums[i] < temp[0]){
                        temp[0] = nums[i];
                    }
                }else if(cnt == 2){
                    if(nums[i] > temp[1]){
                        temp[1] = nums[i];
                    }else if(nums[i] < temp[1]){
                        if(nums[i] > temp[0]) return true;
                        if(nums[i] < temp[0]){
                            if(!stk.empty() && nums[i] >= stk.top()[0]) continue;
                            if(!stk.empty()) stk.pop();
                            vector<int> t;
                            t.resize(4);
                            t[0] = nums[i];
                            t[2] = 1;
                            t[3] = i + 1;
                            stk.push(t);
                        }
                    }
                }
            }
        }
        return false;
    }
};

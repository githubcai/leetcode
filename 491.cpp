class Solution {
    void dfs(const vector<int> &nums, int st, set<vector<int>> &res){
        if(st == nums.size()) return;
        dfs(nums, st + 1, res);
        set<vector<int>> temp = res;
        for(auto iter = temp.begin(); iter != temp.end(); ++iter){
            if(nums[st] <= (*iter)[0]){
                vector<int> vec((*iter).size() + 1);
                vec[0] = nums[st];
                for(int j = 0; j < (*iter).size(); ++j) vec[j + 1] = (*iter)[j];
                res.insert(vec);
            }
        }
        res.insert(vector<int>(1, nums[st]));
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ret;
        set<vector<int>> res;
        dfs(nums, 0, res);
        for(auto iter = res.begin(); iter != res.end(); ++iter){
            if(iter->size() > 1) ret.push_back(*iter);
        }
        return ret;
    }
};

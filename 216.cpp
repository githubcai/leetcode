class Solution {
    void dfs(int k, int st, int sum, int target, vector<int> &vec, int ind, vector<vector<int>> &ret){
        if(st > 10 || sum > target) return;
        if(k == 0){
            if(sum == target) ret.push_back(vec);
            return;
        }
        vec[ind] = st;
        dfs(k - 1, st + 1, sum + st, target, vec, ind + 1, ret);
        dfs(k, st + 1, sum, target, vec, ind, ret);
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ret;
        vector<int> vec(k);
        if(k < 1 || k > 9 || n < 0 || n > 45) return ret;
        dfs(k, 1, 0, n, vec, 0, ret);
        return ret;
    }
};

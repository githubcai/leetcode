class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        if(candidates.size() == 0) return ans;
        vector<int> temp;
        int cnt = 0;
        for(int i = 1; i < candidates.size(); ++i) temp.push_back(candidates[i]);
        while(target > 0){
            vector<vector<int>> tans = combinationSum(temp, target);
            if(tans.size() != 0){
                for(int i = 0; i < tans.size(); ++i){
                    for(int j = 0; j < cnt; ++j) tans[i].push_back(candidates[0]);
                    ans.push_back(tans[i]);
                }
            }
            cnt += 1;
            target -= candidates[0];
        }
        if(target == 0){
            vector<int> ttemp;
            for(int j = 0; j < cnt; ++j) ttemp.push_back(candidates[0]);
            ans.push_back(ttemp);
        }
        return ans;
    }
};

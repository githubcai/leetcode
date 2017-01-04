class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> dp[target + 1];
        for(int i = 0; i < candidates.size(); ++i){
            for(int j = target; j >= candidates[i]; --j){
                int temp = j - candidates[i];
                if(temp == 0){
                    bool flag = true;
                    for(int k = 0; k < dp[j].size(); ++k){
                        if(candidates[i] == dp[j][k][0]){
                            flag = false;
                            break;
                        }
                    }
                    if(flag){
                        vector<int> t;
                        t.push_back(candidates[i]);
                        dp[j].push_back(t);
                    }
                }else{
                    for(int k = 0; k < dp[temp].size(); ++k){
                        vector<int> t;
                        copy(dp[temp][k].begin(), dp[temp][k].end(), back_inserter(t));
                        t.push_back(candidates[i]);
                        sort(t.begin(), t.end());
                        bool flag = true;
                        for(auto iter = dp[j].begin(); iter != dp[j].end(); ++iter){
                            if(iter->size() == t.size()){
                                int n;
                                for(n = 0; n < t.size(); ++n){
                                    if((*iter)[n] != t[n]) break;
                                }
                                if(n == t.size()){
                                    flag = false;
                                    break;
                                }
                            }
                        }
                        if(flag) dp[j].push_back(t);
                    }
                }
            }
        }
        return dp[target];
    }
};

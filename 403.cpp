class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, int> ref;
        int size = stones.size();
        for(int i = 0; i < size; ++i) ref[stones[i]] = i;
        vector<unordered_set<int>> dp(size);
        if(ref.find(1 + stones[0]) != ref.end()) dp[ref[1 + stones[0]]].insert(1);
        for(int i = 1; i < size - 1; ++i){
            for(auto iter = dp[i].begin(); iter != dp[i].end(); ++iter){
                for(int j = -1; j <= 1; ++j){
                    if(j + *iter > 0 && ref.find(j + *iter + stones[i]) != ref.end()){
                        dp[ref[j + *iter + stones[i]]].insert(j + *iter);
                    }
                }
            }
        }
        return dp[size - 1].size() > 0;
    }
};

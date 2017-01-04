class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        if(k > n) return ans;
        if(k == n){
            vector<int> temp;
            for(int i = 1; i <= n; ++i) temp.push_back(i);
            ans.push_back(temp);
            return ans;
        }
        if(k == 1){
            for(int i = 1; i <= n; ++i){
                vector<int> temp;
                temp.push_back(i);
                ans.push_back(temp);
            }
            return ans;
        }
        for(int i = n; i >= k; --i){
            vector<vector<int>> tans;
            tans = combine(i - 1, k - 1);
            for(int j = 0; j < tans.size(); ++j){
                tans[j].push_back(i);
                ans.push_back(tans[j]);
            }
        }
        return ans;
    }
};

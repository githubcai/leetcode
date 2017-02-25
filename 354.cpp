class Solution {
    static bool cmp(const pair<int, int> &a, const pair<int, int> &b){
        if(a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    }
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        int size = envelopes.size();
        if(size < 2) return size;
        sort(envelopes.begin(), envelopes.end(), cmp);
        vector<int> dp(size, 1);
        int ans = 1;
        for(int i = 1; i < size; ++i){
            for(int j = 0; j < i; ++j){
                if(envelopes[i].first > envelopes[j].first && envelopes[i].second > envelopes[j].second && dp[i] < dp[j] + 1) dp[i] = dp[j] + 1;
            }
            if(ans < dp[i]) ans = dp[i];
        }
        return ans;
    }
};

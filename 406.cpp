class Solution {
    static bool cmp(const pair<int, int> &a, const pair<int, int> &b){
        if(a.first == b.first) return a.second < b.second;
        return a.first > b.first;
    }
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(), people.end(), cmp);
        vector<pair<int, int>> ans;
        for(auto per : people) ans.insert(ans.begin() + per.second, per);
        return ans;
    }
};

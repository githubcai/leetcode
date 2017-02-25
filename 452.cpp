class Solution {
    static bool cmp(const pair<int, int> &a, const pair<int, int> &b){
        if(a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    }
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        if(points.size() == 0) return 0;
        sort(points.begin(), points.end(), cmp);
        int ret = 1, ind = 1, ed = points[0].second;
        while(ind < points.size()){
            if(points[ind].first <= ed){
                if(points[ind].second < ed) ed = points[ind].second;
            }else{
                ret += 1;
                ed = points[ind].second;
            }
            ind += 1;
        }
        return ret;
    }
};

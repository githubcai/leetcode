class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        unordered_map<int, int> ref;
        int size = points.size(), ret = 0;
        for(int i = 0; i < size; ++i){
            for(int j = 0; j < size; ++j){
                int x = points[i].first - points[j].first, y = points[i].second - points[j].second;
                int temp = x * x + y * y;
                ref[temp] += 1;
            }
            for(auto iter : ref){
                ret += iter.second * (iter.second - 1);
            }
            ref.clear();
        }
        return ret;
    }
};

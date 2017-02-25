/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
    struct Node{
        Interval val;
        int ind;
    };
    static bool cmp(const Node &a, const Node &b){
        if(a.val.start == b.val.start) return a.val.end < b.val.end;
        return a.val.start < b.val.start;
    }
public:
    vector<int> findRightInterval(vector<Interval>& intervals) {
        vector<Node> vec;
        for(int i = 0; i < intervals.size(); ++i){
            Node node = {intervals[i], i};
            vec.push_back(node);
        }
        sort(vec.begin(), vec.end(), cmp);
        vector<int> ret(vec.size(), -1);
        for(int i = 0; i < vec.size(); ++i){
            int ed = vec[i].val.end;
            for(int j = i + 1; j < vec.size(); ++j){
                if(ed <= vec[j].val.start){
                    ret[vec[i].ind] = vec[j].ind;
                    break;
                }
            }
        }
        return ret;
    }
};

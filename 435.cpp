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
    static bool cmp(const Interval &a, const Interval &b){
        if(a.end == b.end) return a.start > b.start;
        return a.end < b.end;
    }
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        int size = intervals.size();
        if(size < 2) return 0;
        sort(intervals.begin(), intervals.end(), cmp);
        int ret = 0, ed = intervals[0].end;
        for(int i = 1; i < size; ++i){
            if(ed > intervals[i].start){
                ret += 1;
            }else{
                ed = intervals[i].end;
            }
        }
        return ret;
    }
};

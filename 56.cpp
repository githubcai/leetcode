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
        if(a.start == b.start) return a.end < b.end;
        return a.start < b.start;
    }
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.size() <= 0) return intervals;
        vector<Interval> ret;
        sort(intervals.begin(), intervals.end(), cmp);
        int st = intervals[0].start, ed = intervals[0].end;
        for(int i = 1; i < intervals.size(); ++i){
            if(ed >= intervals[i].start){
                if(ed < intervals[i].end) ed = intervals[i].end;
            }else{
                ret.push_back(Interval(st, ed));
                st = intervals[i].start;
                ed = intervals[i].end;
            }
        }
        ret.push_back(Interval(st, ed));
        return ret;
    }
};

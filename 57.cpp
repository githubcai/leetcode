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
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> ret;
        int i = 0;
        for(; i < intervals.size(); ++i){
            if(newInterval.start > intervals[i].end){
                ret.push_back(intervals[i]);
            }else{
                break;
            }
        }
        int st = newInterval.start, ed = newInterval.end;
        for(; i < intervals.size(); ++i){
            if(intervals[i].start > ed) break;
            if(intervals[i].start < st) st = intervals[i].start;
            if(intervals[i].end > ed) ed = intervals[i].end;
        }
        ret.push_back(Interval(st, ed));
        for(; i < intervals.size(); ++i) ret.push_back(intervals[i]);
        return ret;
    }
};

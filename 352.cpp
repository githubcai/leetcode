/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class SummaryRanges {
    vector<Interval> intervals;
    
    int search(int val){
        int left = 0, right = intervals.size() - 1;
        while(left <= right){
            int mid = (left + right) / 2;
            if(val >= intervals[mid].start - 1 && val <= intervals[mid].end + 1) return mid;
            if(val < intervals[mid].start - 1){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return -1;
    }
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        int ind = search(val);
        if(ind == -1){
            int temp = intervals.size();
            while(temp > 0){
                if(val > intervals[temp - 1].end) break;
                temp -= 1;
            }
            intervals.insert(intervals.begin() + temp, Interval(val, val));
        }else{
            if(intervals[ind].start - 1 == val){
                if(ind > 0 && intervals[ind - 1].end + 1 == val){
                    intervals[ind - 1].end = intervals[ind].end;
                    intervals.erase(intervals.begin() + ind);
                }else{
                    intervals[ind].start = val;
                }
            }else if(intervals[ind].end + 1 == val){
                if(ind < intervals.size() - 1 && intervals[ind + 1].start - 1 == val){
                    intervals[ind + 1].start = intervals[ind].start;
                    intervals.erase(intervals.begin() + ind);
                }else{
                    intervals[ind].end = val;
                }
            }
        }
    }
    
    vector<Interval> getIntervals() {
        return intervals;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */

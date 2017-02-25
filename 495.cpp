class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int size = timeSeries.size();
        if(size == 0) return 0;
        int st = timeSeries[0], ed = duration + timeSeries[0], ans = 0;
        for(int i = 1; i < size; ++i){
            if(timeSeries[i] > ed){
                ans += ed - st;
                st = timeSeries[i];
                ed = st + duration;
            }else{
                ed = timeSeries[i] + duration;
            }
        }
        ans += ed - st;
        return ans;
    }
};

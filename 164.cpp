class Solution {
    struct Bucket{
        int count, mn, mx;
        Bucket() : count(0){}
    };
public:
    int maximumGap(vector<int>& nums) {
        int size = nums.size();
        if(size < 2) return 0;
        Bucket buckets[size];
        int mn = INT_MAX, mx = INT_MIN;
        for(int i = 0; i < size; ++i){
            if(mn > nums[i]) mn = nums[i];
            if(mx < nums[i]) mx = nums[i];
        }
        int length = ceil((double)(mx - mn) / (double)(size - 1));
        if(length == 0) return 0;
        for(int i = 0; i < size; ++i){
            int temp = (nums[i] - mn) / length;
            if(buckets[temp].count == 0){
                buckets[temp].count = 1;
                buckets[temp].mx = buckets[temp].mn = nums[i];
            }else{
                buckets[temp].count += 1;
                if(nums[i] > buckets[temp].mx) buckets[temp].mx = nums[i];
                if(nums[i] < buckets[temp].mn) buckets[temp].mn = nums[i];
            }
        }
        int ret = length, pre = buckets[0].mx;
        for(int i = 1; i < size; ++i){
            if(buckets[i].count != 0){
                int temp = buckets[i].mn - pre;
                if(temp > ret) ret = temp;
                pre = buckets[i].mx;
            }
        }
        int temp = mx - pre;
        if(temp > ret) ret = temp;
        return ret;
    }
};

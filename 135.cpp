class Solution {
public:
    int candy(vector<int>& ratings) {
        int size = ratings.size();
        if(size < 2) return size;
        int nums[size];
        for(int i = 0; i < size; ++i) nums[i] = 1;
        for(int i = 1; i < size; ++i){
            if(ratings[i] > ratings[i - 1] && nums[i] <= nums[i - 1]){
                nums[i] = nums[i - 1] + 1;
            }
        }
        int sum = nums[size - 1];
        for(int i = size - 2; i >= 0; --i){
            if(ratings[i] > ratings[i + 1] && nums[i] <= nums[i + 1]){
                nums[i] = nums[i + 1] + 1;
            }
            sum += nums[i];
        }
        return sum;
    }
};

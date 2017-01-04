class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int nl = nums.size(), ans = 0;
        if(nl == 0) return ans;
        int left = 0, sum = 0;
        for(int i = 0; i < nl; ++i){
            sum += nums[i];
            while(sum >= s){
                int temp = i - left + 1;
                if(ans == 0 || temp < ans) ans = temp;
                sum -= nums[left];
                left += 1;
            }
        }
        return ans;
    }
};

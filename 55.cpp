class Solution {
public:
    bool canJump(vector<int>& nums) {
        int left = 0, right = 0;
        for(int i = 0; i < nums.size();){
            if(left > right) break;
            if(right >= nums.size() - 1) return true;
            int mx = right;
            for(int j = left; j <= right; ++j){
                int temp = i + nums[j];
                if(mx < temp) mx = temp;
                i += 1;
            }
            left = right + 1;
            right = mx;
        }
        return false;
    }
};

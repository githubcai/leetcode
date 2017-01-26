struct Node{
    int pos, s;
};

class Solution {
public:
    int jump(vector<int>& nums) {
        int left = 0, right = 0, cnt = 0;
        for(int i = 0; i < nums.size();){
            if(right >= nums.size() - 1) return cnt;
            cnt += 1;
            int mx = right;
            for(int j = left; i< nums.size() && j <= right; ++j){
                int temp = j + nums[j];
                if(temp > mx){
                    mx = temp;
                }
                i += 1;
            }
            left = right + 1;
            right = mx;
        }
        return 0;
    }
};

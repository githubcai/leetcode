class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int cnt[32][2];
        memset(cnt, 0, sizeof(cnt));
        for(int i = 0; i < nums.size(); ++i){
            for(int j = 0; j < 32; ++j){
                if((nums[i] >> j) & 1 == 1){
                    cnt[j][1] += 1;
                }else{
                    cnt[j][0] += 1;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < 32; ++i){
            ans += cnt[i][0] * cnt[i][1];
        }
        return ans;
    }
};

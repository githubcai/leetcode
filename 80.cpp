class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int nLen = nums.size();
        if(nLen == 0) return 0;
        int ind = 0, cnt = 0;
        for(int i = 1; i < nLen; ++i){
            if(nums[i] == nums[ind]){
                if(cnt < 1){
                    nums[++ind] = nums[i];
                    cnt += 1;
                }
            }else{
                nums[++ind] = nums[i];
                cnt = 0;
            }
        }
        return ind + 1;
    }
};

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int size = nums.size();
        int candidate = nums[0], count = 1;
        for(int i = 1; i < size; ++i){
            if(candidate == nums[i]){
                count += 1;
            }else{
                count -= 1;
                if(count == 0){
                    count = 1;
                    candidate = nums[++i];
                }
            }
        }
        return candidate;
    }
};

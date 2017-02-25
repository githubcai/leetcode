class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int size = nums.size();
        if(size < 3) return false;
        int first = nums[0], second, tFirst;
        bool flag = false, tFlag = false;
        for(int i = 1; i < size; ++i){
            if(nums[i] > first){
                if(flag){
                    if(nums[i] > second) return true;
                    if(nums[i] < second){
                        if(tFlag){
                            first = tFirst;
                            tFlag = false;
                        }
                        second = nums[i];
                    }
                }else{
                    second = nums[i];
                    flag = true;
                }
            }else if(nums[i] <= first){
                if(tFlag){
                    if(tFirst > nums[i]){
                        tFirst = nums[i];
                    }else if(nums[i] > tFirst){
                        first = tFirst;
                        second = nums[i];
                        tFlag = false;
                        flag = true;
                    }
                }else{
                    tFirst = nums[i];
                    tFlag = true;
                }
            }
        }
        return false;
    }
};

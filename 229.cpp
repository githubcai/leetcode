class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int size = nums.size();
        vector<int> ret;
        int cand1 = 0, cand2 = 0, cnt1 = 0, cnt2 = 0;
        for(int i = 0; i < size; ++i){
            if(cand1 == nums[i]){
                cnt1 += 1;
            }else if(cand2 == nums[i]){
                cnt2 += 1;
            }else if(cnt1 == 0){
                cand1 = nums[i];
                cnt1 = 1;
            }else if(cnt2 == 0){
                cand2 = nums[i];
                cnt2 = 1;
            }else{
                cnt1 -= 1;
                cnt2 -= 1;
            }
        }
        cnt1 = cnt2 = 0;
        for(int i = 0; i < size; ++i){
            if(cand1 == nums[i]){
                cnt1 += 1;
            }else if(cand2 == nums[i]){
                cnt2 += 1;
            }
        }
        
        if(cnt1 > size / 3) ret.push_back(cand1);
        if(cnt2 > size / 3) ret.push_back(cand2);
        return ret;
    }
};

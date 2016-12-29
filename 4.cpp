class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int temp = nums1.size() + nums2.size();
        bool isEven = false;
        if(temp % 2 == 0) isEven = true;
        temp = (temp + 1) / 2;
        double ans;
        bool flag = false;
        int i, j, cnt = 0, evenCnt = 0;
        for(i = 0, j = 0; i < nums1.size() && j < nums2.size();){
            cnt += 1;
            int tnum;
            if(nums1[i] <= nums2[j]){
                tnum = nums1[i];
                i += 1;
            }else{
                tnum = nums2[j];
                j += 1;
            }
            if(cnt == temp){
                if(isEven){
                    if(evenCnt == 1){
                        ans = (ans + tnum) / 2.0;
                        flag = true;
                        break;
                    }else{
                        ans = tnum;
                        evenCnt += 1;
                        temp += 1;
                    }
                }else{
                    ans = tnum;
                    flag = true;
                    break;
                }
            }
        }
        if(!flag){
            if(i < nums1.size()){
                if(isEven){
                    if(evenCnt == 0){
                        ans = (nums1[i + temp - cnt - 1] + nums1[i + temp - cnt]) / 2.0;
                    }else{
                        ans = (ans + nums1[i]) / 2.0;
                    }
                }else{
                    ans = nums1[i + temp - cnt - 1];
                }
            }else if(j < nums2.size()){
                if(isEven){
                    if(evenCnt == 0){
                        ans = (nums2[j + temp - cnt - 1] + nums2[j + temp - cnt]) / 2.0;
                    }else{
                        ans = (ans + nums2[j]) / 2.0;
                    }
                }else{
                    ans = nums2[j + temp - cnt - 1];
                }
            }
        }
        return ans;
    }
};

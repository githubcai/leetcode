class Solution {
public:
    int mySqrt(int x){
        if(x == 0) return 0;
        long long left = 1, right = x, ans = -1;
        while(left <= right){
            int mid = (left + right) / 2;
            int temp = x / mid;
            if(mid <= temp){
                left = mid + 1;
                if(ans < mid) ans = mid;
            }else{
                right = mid - 1;
            }
        }
        return ans;
    }
};

class Solution {
public:
    int arrangeCoins(int n) {
        if(n <= 0) return 0;
        long long left = 1, right = n, ans;
        while(left <= right){
            long long mid = (left + right) / 2;
            long long temp = mid * (mid + 1) - 2L * n;
            if(temp == 0) return mid;
            if(temp < 0){
                left = mid + 1;
                ans = mid;
            }else{
                right = mid - 1;
            }
        }
        return ans;
    }
};

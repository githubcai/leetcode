// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    long long firstBadVersion(long long n) {
        long long left = 1, right = n, ans = 1;
        while(left <= right){
            long long mid = (left + right) / 2;
            if(isBadVersion(mid)){
                ans = mid;
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return ans;
    }
};

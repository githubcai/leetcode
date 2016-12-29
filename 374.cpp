// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    long long guessNumber(long long n) {
        long long left = 1, right = n;
        while(left < right){
            long long mid = (left + right) / 2;
            int temp = guess(mid);
            if(temp == 0) return mid;
            if(temp == -1){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return left;
    }
};

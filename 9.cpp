class Solution {
public:
    bool isPalindrome(int x) {
        long long temp = 0;
        int tx = x;
        while(tx != 0){
            temp = temp * 10 + tx % 10;
            tx /= 10;
        }
        if(temp < 0) return false;
        return temp == x;
    }
};

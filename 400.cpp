class Solution {
public:
    int findNthDigit(int n) {
        long long cnt = 1, cNum = 9;
        while(n > cNum * cnt){
            n -= cNum * cnt;
            cnt += 1;
            cNum *= 10;
        }
        long long st = 1;
        for(int i = 1; i < cnt; ++i) st *= 10;
        long num = (n - 1) / cnt + st, temp = (n - 1) % cnt;
        for(int i = cnt - 1; i > temp; --i) num /= 10;
        return num % 10;
    }
};

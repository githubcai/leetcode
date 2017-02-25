class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n < 1) return 1;
        if(n > 10) n = 10;
        int ret = 10;
        for(int i = 2; i <= n; ++i){
            int temp = 9, num = 9;
            for(int j = 1; j < i; ++j){
                num *= temp;
                temp -= 1;
            }
            ret += num;
        }
        return ret;
    }
};

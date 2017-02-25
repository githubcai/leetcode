class Solution {
public:
    string convertToBase7(int num) {
        bool neg = false;
        if(num < 0){
            num = -num;
            neg = true;
        }
        string ret;
        while(num > 0){
            int temp = num % 7;
            num /= 7;
            ret += string(1, '0' + temp);
        }
        if(ret == "") return "0";
        if(neg) ret += "-";
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

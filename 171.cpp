class Solution {
public:
    int titleToNumber(string s) {
        int size = s.size() - 1, ret = 0, mul = 26;
        ret = s[size] - 'A';
        for(int i = size - 1; i >= 0; --i){
            int temp = (s[i] - 'A' + 1) * mul;
            ret += temp;
            mul *= 26;
        }
        return ret + 1;
    }
};

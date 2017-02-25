class Solution {
public:
    string toHex(int num) {
        if(num == 0) return "0";
        string ret, table[16] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "a", "b", "c", "d", "e", "f"};
        unsigned tNum = num;
        while(tNum > 0){
            int temp = tNum % 16;
            ret += table[temp];
            tNum /= 16;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

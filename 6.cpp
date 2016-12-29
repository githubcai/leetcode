class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows <= 1) return s;
        string ret;
        int add[2] = {2 * (numRows - 1), 0};
        for(int i = 0; i < numRows && i < s.size(); ++i){
            int temp = 0;
            for(int j = i; j < s.size();){
                ret += s[j];
                if(add[temp] == 0) temp ^= 1;
                j += add[temp];
                temp ^= 1;
            }
            add[0] -= 2;
            add[1] += 2;
        }
        return ret;
    }
};

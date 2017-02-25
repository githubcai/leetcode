class Solution {
public:
    string originalDigits(string s) {
        //zero one two three four five six seven eight nine
        vector<char> c = {'z', 'x', 's', 'v', 'f', 'g', 'i', 'n', 'w', 'r'};
        vector<string> num = {"zero", "six", "seven", "five", "four", "eight", "nine", "one", "two", "three"};
        vector<int> cCnt(26, 0), nNum(10, 0), ref = {0, 6, 7, 5, 4, 8, 9, 1, 2, 3};
        for(int i = 0; i < s.size(); ++i) cCnt[s[i] - 'a'] += 1;
        for(int i = 0; i < c.size(); ++i){
            if(cCnt[c[i] - 'a'] != 0){
                int temp = cCnt[c[i] - 'a'];
                nNum[ref[i]] += temp;
                for(int j = 0; j < num[i].size(); ++j){
                    cCnt[num[i][j] - 'a'] -= temp;
                }
            }
        }
        string ret;
        for(int i = 0; i < 10; ++i){
            if(nNum[i] != 0){
                ret += string(nNum[i], '0' + i);
            }
        }
        return ret;
    }
};

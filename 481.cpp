class Solution {
public:
    int magicalString(int n) {
        string str = "122";
        int ind = 2;
        while(str.size() < n){
            str += string(str[ind++] - '0', str.back() == '1' ? '2' : '1');
        }
        return count(str.begin(), str.begin() + n, '1');
    }
};

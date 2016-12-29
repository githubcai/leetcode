class Solution {
public:
    string addStrings(string num1, string num2) {
        string ret;
        int c = 0, i, j;
        for(i = num1.size() - 1, j = num2.size() - 1; i >= 0 && j >= 0; --i, --j){
            int temp = num1[i] - '0' + num2[j] - '0' + c;
            c = temp / 10;
            temp %= 10;
            ret += (temp + '0');
        }
        while(i >= 0){
            int temp = num1[i] - '0' + c;
            c = temp / 10;
            temp %= 10;
            ret += (temp + '0');
            i -= 1;
        }
        while(j >= 0){
            int temp = num2[j] - '0' + c;
            c = temp / 10;
            temp %= 10;
            ret += (temp + '0');
            j -= 1;
        }
        if(c != 0) ret += (c + '0');
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

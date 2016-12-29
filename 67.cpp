class Solution {
public:
    string addBinary(string a, string b) {
        string ret;
        int i, j, r = 0;
        for(i = a.size() - 1, j = b.size() - 1; i >= 0 && j >= 0; --i, --j){
            int temp = a[i] - '0' + b[j] - '0' + r;
            r = temp / 2;
            temp %= 2;
            ret += (temp + '0');
        }
        while(i >= 0){
            int temp = a[i] - '0' + r;
            r = temp / 2;
            temp %= 2;
            ret += (temp + '0');
            i -= 1;
        }
        while(j >= 0){
            int temp = b[j] - '0' + r;
            r = temp / 2;
            temp %= 2;
            ret += (temp + '0');
            j -= 1;
        }
        if(r != 0) ret += (r + '0');
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

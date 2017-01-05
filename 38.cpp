class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        string ret, temp = countAndSay(n - 1);
        for(int i = 0; i < temp.size(); ){
            int cnt = 1, pre = temp[i++] - '0';
            while(i < temp.size() && pre == temp[i] - '0') i += 1, cnt += 1;
            ret += cnt + '0';
            ret += pre + '0';
        }
        return ret;
    }
};

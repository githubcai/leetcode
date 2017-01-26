class Solution {
    void dfs(vector<string> &ret, const string &s, const int &slen, int ind, int cnt, const string &res){
        if(cnt == 0){
            if((s[ind] == '0' && slen - ind > 1) || ind >= slen) return;
            string temp;
            int num = 0;
            for(int i = ind; i < slen; ++i){
                num = 10 * num + (s[i] - '0');
                temp += s[i];
            }
            if(num >= 0 && num < 256){
                ret.push_back(res + "." + temp);
            }
            return;
        }
        int num = 0;
        string str;
        if(cnt != 3) str += ".";
        while(ind < slen){
            num = 10 * num + (s[ind] - '0');
            if(num > 255) break;
            str += s[ind++];
            if(slen - ind >= cnt && slen - ind <= 3 * cnt) dfs(ret, s, slen, ind, cnt - 1, res + str);
            if((cnt == 3 && str[0] == '0') || (cnt != 3 && str[1] == '0') || slen - ind < cnt) break;
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        int slen = s.size();
        vector<string> ret;
        if(slen < 4 || slen > 12) return ret;
        string str;
        dfs(ret, s, slen, 0, 3, str);
        return ret;
    }
};

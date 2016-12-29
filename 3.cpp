class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ret = 0;
        bool flag[130];
        for(int i = 0; i < s.size(); ++i){
            memset(flag, 0, sizeof(flag));
            int cnt = 1;
            ret = max(ret, cnt);
            flag[s[i]] = true;
            for(int j = i + 1; j < s.size(); ++j){
                if(!flag[s[j]]){
                    flag[s[j]] = true;
                    cnt += 1;
                    ret = max(ret, cnt);
                }else{
                    break;
                }
            }
        }
        return ret;
    }
};

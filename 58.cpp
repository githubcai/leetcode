class Solution {
public:
    int lengthOfLastWord(string s) {
        int ret = 0;
        auto iter = s.rbegin();
        for(; iter != s.rend() && *iter == ' '; ++iter);
        for(; iter != s.rend() && *iter != ' '; ++iter) ret += 1;
        return ret;
    }
};

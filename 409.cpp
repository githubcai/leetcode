class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> ref;
        for(char c : s) ref[c] += 1;
        bool flag = false;
        int ret = 0;
        for(auto iter : ref){
            if(iter.second % 2 == 0){
                ret += iter.second;
            }else{
                flag = true;
                ret += iter.second - 1;
            }
        }
        if(flag) ret += 1;
        return ret;
    }
};

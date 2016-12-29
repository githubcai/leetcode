class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() == 0) return "";
        int left = 0, right = 0, ret = 1;
        for(int i = 0; i < s.size(); ++i){
            int temp = 1;
            for(int j = i + 1, k = i - 1; j < s.size() && k >= 0; ++j, --k){
                if(s[j] != s[k]) break;
                temp += 2;
                if(ret < temp){
                    left = k;
                    right = j;
                    ret = temp;
                }
            }
            temp = 0;
            for(int j = i, k = i - 1; j < s.size() && k >= 0; ++j, --k){
                if(s[j] != s[k]) break;
                temp += 2;
                if(ret < temp){
                    left = k;
                    right = j;
                    ret = temp;
                }
            }
        }
        string ans = "";
        for(int i = left; i <= right; ++i){
            ans += s[i];
        }
        return ans;
    }
};

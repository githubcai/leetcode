class Solution {
    vector<int> getNext(string str){
        vector<int> next;
        next.push_back(0);
        for(int i = 1, j = 0; i < str.size(); ++i){
            if(j > 0 && str[i] != str[j]) j = next[j - 1];
            if(str[i] == str[j]) ++j;
            next.push_back(j);
        }
        return next;
    }
    
public:
    string shortestPalindrome(string s) {
        string str = s;
        reverse(str.begin(), str.end());
        str = s + '$' + str;
        vector<int> next = getNext(str);
        string ret;
        for(int i = s.size() - 1; i >= next[str.size() - 1]; --i){
            ret += s[i];
        }
        ret += s;
        return ret;
    }
};

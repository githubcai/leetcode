class Solution {
    vector<int> getNext(string needle){
        vector<int> next;
        next.push_back(0);
        for(int i = 1, j = 0; i < needle.size(); ++i){
            while(j > 0 && needle[i] != needle[j]) j = next[j - 1];
            if(needle[i] == needle[j]) ++j;
            next.push_back(j);
        }
        return next;
    }
    
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0) return 0;
        vector<int> next = getNext(needle);
        for(int i = 0, j = 0; i < haystack.size(); ++i){
            while(j > 0 && needle[j] != haystack[i]) j = next[j - 1];
            if(haystack[i] == needle[j]) ++j;
            if(j == needle.size()) return i - needle.size() + 1;
        }
        return -1;
    }
};

class Solution {
    vector<int> getNext(string str){
        vector<int> next;
        next.push_back(0);
        for(int i = 1, j = 0; i < str.size(); ++i){
            while(j > 0 && str[i] != str[j]) j = next[j - 1];
            if(str[i] == str[j]) ++j;
            next.push_back(j);
        }
        return next;
    }
public:
    bool repeatedSubstringPattern(string str) {
        if(str.size() == 1) return false;
        vector<int> next = getNext(str);
        if(next[str.size() - 1] >= str.size() / 2 && next[str.size() - 1] % (str.size() - next[str.size() - 1]) == 0) return true;
        return false;
    }
};

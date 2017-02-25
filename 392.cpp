class Solution {
public:
    bool isSubsequence(string s, string t) {
        int slen = s.size(), tlen = t.size();
        int sInd, tInd;
        for(sInd = slen - 1, tInd = tlen - 1; sInd >= 0 && tInd >= 0;){
            if(s[sInd] == t[tInd]) sInd -= 1;
            tInd -= 1;
        }
        if(sInd < 0) return true;
        return false;
    }
};

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> sRef, tRef;
        int size = s.size();
        for(int i = 0; i < size; ++i){
            auto sIter = sRef.find(s[i]), tIter = tRef.find(t[i]);
            if(sIter == sRef.end() && tIter == tRef.end()){
                sRef[s[i]] = t[i];
                tRef[t[i]] = s[i];
            }else{
                if(sIter != sRef.end() && tIter != tRef.end()){
                    if(sRef[s[i]] != t[i] || tRef[t[i]] != s[i]) return false;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};

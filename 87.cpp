class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1.size() != s2.size()) return false;
        int leng = s1.size();
        string t1 = s1, t2 = s2;;
        sort(t1.begin(), t1.end());
        sort(t2.begin(), t2.end());
        if(t1 != t2) return false;
        if(leng == 1 || leng == 2) return true;
        for(int i = 1; i < leng; ++i){
            string ls1, rs1, ls2, rs2;
            ls1 = s1.substr(0, i); rs1 = s1.substr(i, leng - i);
            ls2 = s2.substr(0, i); rs2 = s2.substr(i, leng - i);
            if(isScramble(ls1, ls2) && isScramble(rs1, rs2)) return true;
            ls2 = s2.substr(0, leng - i); rs2 = s2.substr(leng - i, i);
            if(isScramble(ls1, rs2) && isScramble(rs1, ls2)) return true;
        }
        return false;
    }
};

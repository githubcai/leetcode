class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> sVec;
        string temp = "";
        for(int i = 0; i < str.size(); ++i){
            if(str[i] != ' '){
                temp += string(1, str[i]);
            }else{
                sVec.push_back(temp);
                temp = "";
            }
        }
        if(temp != "") sVec.push_back(temp);
        if(pattern.size() != sVec.size()) return false;
        unordered_map<char, string> ref1;
        unordered_map<string, char> ref2;
        for(int i = 0; i < pattern.size(); ++i){
            auto iter1 = ref1.find(pattern[i]);
            auto iter2 = ref2.find(sVec[i]);
            if(iter1 == ref1.end() && iter2 == ref2.end()){
                ref1[pattern[i]] = sVec[i];
                ref2[sVec[i]] = pattern[i];
            }else if(iter1 != ref1.end() && iter2 != ref2.end()){
                if(ref1[pattern[i]] != sVec[i] || ref2[sVec[i]] != pattern[i]) return false;
            }else{
                return false;
            }
        }
        return true;
    }
};

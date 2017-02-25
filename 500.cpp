class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string strs[3] = {"qwertyuiopQWERTYUIOP", "asdfghjklASDFGHJKL", "zxcvbnmZXCVBNM"};
        vector<string> ret;
        for(string str : words){
            int sizeS = str.size(), row;
            if(sizeS == 0){
                ret.push_back(str);
                continue;
            }
            for(row = 0; row < 3; ++row){
                if(strs[row].find(str[0]) != string::npos) break;
            }
            int ind;
            for(ind = 1; ind < sizeS; ++ind){
                if(strs[row].find(str[ind]) == string::npos) break;
            }
            if(ind >= sizeS) ret.push_back(str);
        }
        return ret;
    }
};

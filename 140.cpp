class Solution {
    unordered_map<string, vector<string>> ref;
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int size = s.size();
        vector<string> ret;
        for(int i = 1; i <= size; ++i){
            string temp = s.substr(0, i);
            bool flag = false;
            for(int j = 0; j < wordDict.size(); ++j){
                if(wordDict[j] == temp){
                    flag = true;
                    break;
                }
            }
            if(flag){
                if(i == size){
                    ret.push_back(s);
                    break;
                }
                vector<string> tRet;
                string str = s.substr(i, size - i);
                if(ref.find(str) != ref.end()){
                    tRet = ref[str];
                }else{
                    tRet = wordBreak(str, wordDict);
                    ref[str] = tRet;
                }
                for(int j = 0; j < tRet.size(); ++j){
                    ret.push_back(temp + " " + tRet[j]);
                }
            }
        }
        ref[s] = ret;
        return ret;
    }
};

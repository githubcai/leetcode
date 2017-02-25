class Solution {
    unordered_set<string> dic;
    
    bool search(const string &str){
        if(dic.find(str) != dic.end()) return true;
        int size = str.size();
        for(int i = 1; i < size; ++i){
            string temp = str.substr(0, i);
            if(dic.find(temp) != dic.end()){
                temp = str.substr(i, size - i);
                if(search(temp)) return true;
            }
        }
        return false;
    }
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        for(int i = 0; i < words.size(); ++i) dic.insert(words[i]);
        vector<string> ret;
        int size = words.size();
        for(int i = 0; i < size; ++i){
            dic.erase(words[i]);
            if(search(words[i])) ret.push_back(words[i]);
            dic.insert(words[i]);
        }
        return ret;
    }
};

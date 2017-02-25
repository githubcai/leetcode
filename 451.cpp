class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> ref;
        for(int i = 0; i < s.size(); ++i) ref[s[i]] += 1;
        map<int, vector<char>> store;
        for(auto iter = ref.begin(); iter != ref.end(); ++iter){
            store[iter->second].push_back(iter->first);
        }
        string ret;
        for(auto iter = store.rbegin(); iter != store.rend(); ++iter){
            for(int i = 0; i < iter->second.size(); ++i){
                string temp(iter->first, (iter->second)[i]);
                ret += temp;
            }
        }
        return ret;
    }
};

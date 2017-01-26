class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        unordered_map<string, int> ref;
        int cnt = 0;
        for(int i = 0; i < strs.size(); ++i){
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            if(ref[temp] == 0){
                ref[temp] = ++cnt;
                vector<string> t;
                t.push_back(strs[i]);
                ret.push_back(t);
            }else{
                ret[ref[temp] - 1].push_back(strs[i]);
            }
        }
        return ret;
    }
};

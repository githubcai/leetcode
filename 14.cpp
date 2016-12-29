class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        if(strs.size() == 1) return strs[0];
        string ans;
        for(int i = 0; ; ++i){
            char temp = strs[0][i];
            for(int j = 1; j < strs.size(); ++j){
                if(i >= strs[j].size() || strs[j][i] != temp) return ans;
            }
            ans += temp;
        }
        return ans;
    }
};

class Solution {
    string table[10] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string input;
    void dfs(vector<string> &ret, int index, string res){
        if(index == input.size()){
            ret.push_back(res);
            return;
        }
        int temp = input[index] - '0';
        for(int i = 0; i < table[temp].size(); ++i){
            dfs(ret, index + 1, res + table[temp][i]);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        if(digits.size() == 0) return ret;
        input = digits;
        dfs(ret, 0, "");
        return ret;
    }
};

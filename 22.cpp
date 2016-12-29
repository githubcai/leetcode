class Solution {
    
    void dfs(vector<string> &ret, int tl, int tr, int ul, string res){
        if(tl == 0 && tr == 0){
            ret.push_back(res);
            return;
        }
        if(tl != 0) dfs(ret, tl - 1, tr, ul + 1, res + '(');
        if(ul != 0) dfs(ret, tl, tr - 1, ul - 1, res + ')');
    }
    
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        if(n <= 0) return ret;
        dfs(ret, n, n, 0, "");
        return ret;
    }
};

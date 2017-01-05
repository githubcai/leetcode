class Solution {
    vector<vector<string>> ret;
    int total;
    
    void dfs(const vector<int> &pos){
        if(pos.size() == total){
            vector<string> board;
            for(int i = 0; i < total; ++i){
                string temp(total, '.');
                board.push_back(temp);
            }
            for(int i = 0; i < pos.size(); ++i){
                board[i][pos[i]] = 'Q';
            }
            ret.push_back(board);
            return;
        }
        for(int i = 0; i < total; ++i){
            bool flag = true;
            for(int j = 0; j < pos.size(); ++j){
                if(i == pos[j] || fabs(pos.size() - j) == fabs(i - pos[j])){
                    flag = false;
                    break;
                }
            }
            if(flag){
                vector<int> tpos;
                copy(pos.begin(), pos.end(), back_inserter(tpos));
                tpos.push_back(i);
                dfs(tpos);
            }
        }
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int> pos;
        ret.clear();
        total = n;
        dfs(pos);
        return ret;
    }
};

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        if(board.size() == 0 || board[0].size() == 0) return 0;
        int ret = 0, rows = board.size(), cols = board[0].size();
        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < cols; ++j){
                if(board[i][j] == 'X' && (j + 1 == cols || board[i][j + 1] == '.') && (i + 1 == rows || board[i + 1][j] == '.')) ret += 1;
            }
        }
        return ret;
    }
};

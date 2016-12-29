class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][10] = {false}, col[9][10] = {false}, block[9][10] = {false};
        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 9; ++j){
                if(board[i][j] == '.') continue;
                int temp = board[i][j] - '0';
                if(row[i][temp] || col[j][temp] || block[(i / 3) * 3 + j / 3][temp]) return false;
                row[i][temp] = col[j][temp] = block[(i / 3) * 3 + j / 3][temp] = true;
            }
        }
        return true;
    }
};

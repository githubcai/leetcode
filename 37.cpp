class Solution {
    bool row[9][10], col[9][10], block[9][10], flag;
    vector<vector<int>> pos;
    
    void init(const vector<vector<char>> &board){
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        memset(block, 0, sizeof(block));
        pos.clear();
        flag = false;
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[i].size(); ++j){
                if(board[i][j] != '.'){
                    row[i][board[i][j] - '0'] = true;
                    col[j][board[i][j] - '0'] = true;
                    int temp = (i / 3) * 3 + (j / 3);
                    block[temp][board[i][j] - '0'] = true;
                }else{
                    vector<int> temp;
                    temp.push_back(i);
                    temp.push_back(j);
                    pos.push_back(temp);
                }
            }
        }
    }
    
    void dfs(vector<vector<char>> &board, int cnt){
        if(flag) return;
        if(cnt == pos.size()){
            flag = true;
            return;
        }
        int x = pos[cnt][0], y = pos[cnt][1];
        int temp = (x / 3) * 3 + (y / 3);
        for(int i = 1; i <= 9 && !flag; ++i){
            if(!row[x][i] && !col[y][i] && !block[temp][i]){
                board[x][y] = i + '0';
                row[x][i] = col[y][i] = block[temp][i] = true;
                dfs(board, cnt + 1);
                row[x][i] = col[y][i] = block[temp][i] = false;
            }
        }
    }
    
public:
    void solveSudoku(vector<vector<char>>& board) {
        init(board);
        dfs(board, 0);
    }
};

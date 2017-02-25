class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size(), cols;
        if(rows == 0 || (cols = board[0].size()) == 0) return;
        int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<pair<int, int>> que;
        for(int i = 0; i < cols; ++i){
            if(board[0][i] == 'O') que.push(make_pair(0, i)), board[0][i] = '1';
            if(board[rows - 1][i] == 'O') que.push(make_pair(rows - 1, i)), board[rows - 1][i] = '1';
        }
        for(int i = 0; i < rows; ++i){
            if(board[i][0] == 'O') que.push(make_pair(i, 0)), board[i][0] = '1';
            if(board[i][cols - 1] == 'O') que.push(make_pair(i, cols - 1)), board[i][cols - 1] = '1';
        }
        while(!que.empty()){
            pair<int, int> now = que.front();
            que.pop();
            for(int i = 0; i < 4; ++i){
                int x = now.first + dir[i][0], y = now.second + dir[i][1];
                if(x >= 0 && x < rows && y >= 0 && y < cols && board[x][y] == 'O'){
                    board[x][y] = '1';
                    que.push(make_pair(x, y));
                }
            }
        }
        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < cols; ++j){
                if(board[i][j] == '1'){
                    board[i][j] = 'O';
                }else if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};

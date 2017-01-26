class Solution {
    int nRow, nCol, dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    string target;
    
    bool dfs(int x, int y, int d, vector<vector<char>> &board, vector<vector<int>> &vis){
        if(d == target.size()) return true;
        for(int i = 0; i < 4; ++i){
            int tx = x + dir[i][0], ty = y + dir[i][1];
            if(tx < 0 || tx >= nRow || ty < 0 || ty >= nCol || vis[tx][ty] || board[tx][ty] != target[d]) continue;
            vis[tx][ty] = true;
            if(dfs(tx, ty, d + 1, board, vis)) return true;
            vis[tx][ty] = false;
        }
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size() == 0) return false;
        if(word.size() == 0) return true;
        nRow = board.size();
        nCol = board[0].size();
        target = word;
        vector<vector<int>> vis(nRow, vector<int>(nCol, false));
        for(int i = 0; i < nRow; ++i){
            for(int j = 0; j < nCol; ++j){
                if(board[i][j] == word[0]){
                    vis[i][j] = true;
                    if(dfs(i, j, 1, board, vis)) return true;
                    vis[i][j] = false;
                }
            }
        }
        return false;
    }
};

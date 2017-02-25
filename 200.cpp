class Solution {
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    void dfs(vector<vector<char>> &grid, int x, int y, int rows, int cols){
        for(int i = 0; i < 4; ++i){
            int tx = x + dir[i][0], ty = y + dir[i][1];
            if(tx >= 0 && tx < rows && ty >= 0 && ty < cols && grid[tx][ty] == '1'){
                grid[tx][ty] = '0';
                dfs(grid, tx, ty, rows, cols);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size(), cols, cnt = 0;
        if(rows == 0 || (cols = grid[0].size()) == 0) return cnt;
        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < cols; ++j){
                if(grid[i][j] == '1'){
                    cnt += 1;
                    grid[i][j] = '0';
                    dfs(grid, i, j, rows, cols);
                }
            }
        }
        return cnt;
    }
};

class Solution {
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(grid[i][j] == 0) continue;
                for(int k = 0; k < 4; ++k){
                    int x = i + dir[k][0], y = j + dir[k][1];
                    if(x < 0 || x >= n || y < 0 || y >= m){
                        ++ans;
                    }else{
                        if(grid[x][y] == 0) ++ans;
                    }
                }
            }
        }
        return ans;
    }
};

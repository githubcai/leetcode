class Solution {
    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        if(matrix.size() == 0) return ret;
        int xlen = matrix.size(), ylen = matrix[0].size();
        bool vis[xlen][ylen];
        memset(vis, 0, sizeof(vis));
        int x = 0, y = 0;
        vis[x][y] = true;
        ret.push_back(matrix[0][0]);
        bool flag = true;;
        while(flag){
            int cnt = 0;
            for(int i = 0; i < 4; ++i){
                int tx = x + dir[i][0], ty = y + dir[i][1];
                if(tx < 0 || tx >= xlen || ty < 0 || ty >= ylen){
                    cnt += 1;
                    continue;
                }
                if(vis[tx][ty]){
                    flag = false;
                    break;
                }
                while(tx >= 0 && tx < xlen && ty >= 0 && ty < ylen && !vis[tx][ty]){
                    vis[tx][ty] = true;
                    ret.push_back(matrix[tx][ty]);
                    tx = tx + dir[i][0], ty = ty + dir[i][1];
                }
                x = tx - dir[i][0], y = ty - dir[i][1];
            }
            if(cnt == 4) break;
        }
        return ret;
    }
};

class Solution {
    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret(n, vector<int>(n, 0));
        if(n <= 0) return ret;
        bool flag = true;
        int x = 0, y = 0, cnt = 1;
        ret[x][y] = cnt++;
        while(flag){
            int tcnt = 0;
            for(int i = 0; i < 4; ++i){
                int tx = x + dir[i][0], ty = y + dir[i][1];
                if(tx < 0 || tx >= n || ty < 0 || ty >= n){
                    tcnt += 1;
                    continue;
                }
                if(ret[tx][ty] != 0){
                    flag = false;
                    break;
                }
                while(tx >= 0 && tx < n && ty >= 0 && ty < n && ret[tx][ty] == 0){
                    ret[tx][ty] = cnt++;
                    tx = tx + dir[i][0], ty = ty + dir[i][1];
                }
                x = tx - dir[i][0], y = ty - dir[i][1];
            }
            if(tcnt == 4) break;
        }
        return ret;
    }
};

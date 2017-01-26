struct Node{
    int x, y, h;
    friend bool operator<(const Node &a, const Node &b){
        return a.h > b.h;
    }
};

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if(heightMap.size() == 0) return 0; 
        int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        priority_queue<Node> que;
        bool vis[heightMap.size()][heightMap[0].size()];
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < heightMap[0].size(); ++i){
            vis[0][i] = vis[heightMap.size() - 1][i] = true;
            Node temp;
            temp.x = 0, temp.y = i, temp.h = heightMap[0][i]; que.push(temp);
            temp.x = heightMap.size() - 1, temp.y = i, temp.h = heightMap[heightMap.size() - 1][i]; que.push(temp);
        }
        for(int i = 1; i < heightMap.size() - 1; ++i){
            vis[i][0] = vis[i][heightMap[0].size() - 1] = true;
            Node temp;
            temp.x = i, temp.y = 0, temp.h = heightMap[i][0]; que.push(temp);
            temp.x = i, temp.y = heightMap[0].size() - 1, temp.h = heightMap[i][heightMap[0].size() - 1]; que.push(temp);
        }
        int water = 0, level = 0;
        while(!que.empty()){
            Node now = que.top();
            que.pop();
            level = max(level, now.h);
            water += level - now.h;
            for(int i = 0; i < 4; ++i){
                int x = now.x + dir[i][0], y = now.y + dir[i][1];
                if(x >= 0 && x < heightMap.size() && y >= 0 && y < heightMap[0].size() && !vis[x][y]){
                    vis[x][y] = true;
                    Node nxt;
                    nxt.x = x, nxt.y = y, nxt.h = heightMap[x][y];
                    que.push(nxt);
                }
            }
        }
        return water;
    }
};

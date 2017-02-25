class Solution {
    struct Node{
        int val, x, y;
        friend bool operator<(const Node &a, const Node &b){
            return a.val > b.val;
        }
    };
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int rows = matrix.size(), cols = matrix[0].size();
        priority_queue<Node> que;
        for(int i = 0; i < rows; ++i){
            Node node = {matrix[i][0], i, 0};
            que.push(node);
        }
        while(k-- > 1){
            Node node = que.top();
            que.pop();
            node.y += 1;
            if(node.y < cols){
                node.val = matrix[node.x][node.y];
                que.push(node);
            }
        }
        return (que.top()).val;
    }
};

class Solution {
    static const int MAX = 26;
    struct Node{
        bool flag;
        Node *next[MAX];
        Node(){
            flag = false;
            memset(next, 0, sizeof(next));
        }
    };
    
    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}, nRow, nCol;
    Node *root;
    
    void delTrie(Node *cur){
        if(cur == NULL) return;
        for(int i = 0; i < MAX; ++i){
            if(cur->next[i] != NULL) delTrie(cur->next[i]);
        }
        delete cur;
    }
        
    void insert(const string &str){
        int size = str.size();
        Node *temp = root;
        for(int i = 0; i < size; ++i){
            if(temp->next[str[i] - 'a'] == NULL){
                Node *cur = new Node();
                temp->next[str[i] - 'a'] = cur;
            }
            temp = temp->next[str[i] - 'a'];
        }
        temp->flag = true;
    }
    
    void dfs(const vector<vector<char>> &board, int x, int y, Node* node, string str, vector<string> &ret, vector<vector<bool>> vis){
        if(node->next[board[x][y] - 'a'] == NULL) return;
        str += string(1, board[x][y]);
        node = node->next[board[x][y] - 'a'];
        if(node->flag){
            node->flag = false;
            ret.push_back(str);
        }
        vis[x][y] = true;
        for(int i = 0; i < 4; ++i){
            int tx = x + dir[i][0], ty = y + dir[i][1];
            if(tx >= 0 && tx < nRow && ty >= 0 && ty < nCol && !vis[tx][ty]){
                dfs(board, tx, ty, node, str, ret, vis);
            }
        }
        vis[x][y] = false;
    }
    
public:
    Solution(){
        root = new Node();
    }
    
    ~Solution(){
        delTrie(root);
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ret;
        if(board.size() == 0 || words.size() == 0) return ret;
        nRow = board.size(), nCol = board[0].size();
        for(int i = 0; i < words.size(); ++i) insert(words[i]);
        vector<vector<bool>> vis(nRow, vector<bool>(nCol, false));
        for(int i = 0; i < nRow; ++i){
            for(int j = 0; j < nCol; ++j){
                string str;
                dfs(board, i, j, root, str, ret, vis);
            }
        }
        return ret;
    }
};

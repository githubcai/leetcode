class Trie {
    static const int MAX = 26;
    struct Node{
        bool flag;
        Node *next[MAX];
        Node(){
            flag = false;
            memset(next, 0, sizeof(next));
        }
    };
    Node *root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int size = word.size();
        Node *now = root;
        for(int i = 0; i < size; ++i){
            if(now->next[word[i] - 'a'] == NULL){
                Node *temp = new Node();
                now->next[word[i] - 'a'] = temp;
            }
            now = now->next[word[i] - 'a'];
        }
        now->flag = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int size = word.size();
        Node *now = root;
        for(int i = 0; i < size; ++i){
            if(now->next[word[i] - 'a'] == NULL) return false;
            now = now->next[word[i] - 'a'];
        }
        if(!now->flag) return false;
        return true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int size = prefix.size();
        Node *now = root;
        for(int i = 0; i < size; ++i){
            if(now->next[prefix[i] - 'a'] == NULL) return false;
            now = now->next[prefix[i] - 'a'];
        }
        return true;
    }
    
    void delTrie(Node *cur){
        if(cur == NULL) return;
        for(int i = 0; i < MAX; ++i){
            if(cur->next[i] != NULL) delTrie(cur->next[i]);
        }
        delete cur;
    }
    
    ~Trie(){
        delTrie(root);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */

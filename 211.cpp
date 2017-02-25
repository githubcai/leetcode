class WordDictionary {
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
    
    void delTrie(Node *cur){
        if(cur == NULL) return;
        for(int i = 0; i < MAX; ++i){
            if(cur->next[i] != NULL) delTrie(cur->next[i]);
        }
        delete cur;
    }
    
    bool searchWord(const string &word, int st, Node *cur){
        if(st == word.size()){
            if(cur->flag) return true;
            return false;
        }
        if(word[st] == '.'){
            for(int i = 0; i < MAX; ++i){
                if(cur->next[i] != NULL){
                    bool temp = searchWord(word, st + 1, cur->next[i]);
                    if(temp) return true;
                }
            }
        }else{
            if(cur->next[word[st] - 'a'] == NULL) return false;
            bool temp = searchWord(word, st + 1, cur->next[word[st] - 'a']);
            if(temp) return true;
        }
        return false;
    }
    
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Node();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
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
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        if(word.size() == 0) return true;
        return searchWord(word, 0, root);
    }
    
    ~WordDictionary(){
        delTrie(root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */

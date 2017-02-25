class LRUCache {
    struct Node{
        int value;
        int key;
        Node *next, *pre;
        Node(int val) : value(val), key(val), next(NULL), pre(NULL){}
    };
    Node *head, *tail;
    unordered_map<int, Node*> nodeRef;
public:
    LRUCache(int capacity) {
        head = NULL;
        tail = head = new Node(-2);
        for(int i = 0; i < capacity; ++i){
            Node *temp = new Node(-2);
            tail->next = temp;
            temp->pre = tail;
            tail = temp;
        }
    }
    
    int get(int key) {
        auto iter = nodeRef.find(key);
        if(iter != nodeRef.end()){
            Node *temp = iter->second;
            if(temp->next != NULL){
                temp->pre->next = temp->next;
                temp->next->pre = temp->pre;
                temp->next = NULL;
                temp->pre = tail;
                tail->next = temp;
                tail = temp;
            }
            return tail->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        auto iter = nodeRef.find(key);
        if(iter != nodeRef.end()){
            Node *temp = iter->second;
            if(temp->next != NULL){
                temp->pre->next = temp->next;
                temp->next->pre = temp->pre;
                tail->next = temp;
                temp->pre = tail;
                temp->next = NULL;
                tail = temp;
            }
            tail->value = value;
        }else{
            Node *temp = head->next;
            if(temp != NULL){
                if(temp->next != NULL){
                    head->next = temp->next;
                    temp->next->pre = temp->pre;
                    temp->pre = tail;
                    temp->next = NULL;
                    tail->next = temp;
                    tail = temp;
                }
                iter = nodeRef.find(tail->key);
                if(iter != nodeRef.end()){
                    nodeRef.erase(iter);
                }
                tail->value = value;
                tail->key = key;
                nodeRef[key] = tail;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

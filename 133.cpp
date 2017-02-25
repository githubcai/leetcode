/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        UndirectedGraphNode *ret = NULL;
        if(node == NULL) return ret;
        queue<pair<UndirectedGraphNode*, UndirectedGraphNode*>> que;
        map<int, UndirectedGraphNode*> ref;
        ret = new UndirectedGraphNode(node->label);
        ref[ret->label] = ret;
        que.push(make_pair(ret, node));
        while(!que.empty()){
            auto now = que.front();
            que.pop();
            int size = now.second->neighbors.size();
            for(int i = 0; i < size; ++i){
                UndirectedGraphNode *temp;
                if(ref[now.second->neighbors[i]->label] == NULL){
                    temp = new UndirectedGraphNode(now.second->neighbors[i]->label);
                    ref[now.second->neighbors[i]->label] = temp;
                    que.push(make_pair(temp, now.second->neighbors[i]));
                }else{
                    temp = ref[now.second->neighbors[i]->label];
                }
                now.first->neighbors.push_back(temp);
            }
        }
        return ret;
    }
};

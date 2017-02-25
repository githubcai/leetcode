class Solution {
    struct Edge{
        int to, next;
    };
    
    void addEdge(int from, int to, vector<Edge> &edges, vector<int> &head){
        Edge e = {to, head[from]};
        head[from] = edges.size();
        edges.push_back(e);
    }
    
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<Edge> edges;
        vector<int> indegree(numCourses, 0), head(numCourses, -1), ret;
        int size = prerequisites.size();
        for(int i = 0; i < size; ++i){
            auto temp = prerequisites[i];
            indegree[temp.first] += 1;
            addEdge(temp.second, temp.first, edges, head);
        }
        queue<int> que;
        for(int i = 0; i < numCourses; ++i){
            if(indegree[i] == 0){
                que.push(i);
                ret.push_back(i);
            }
        }
        while(!que.empty()){
            int now = que.front();
            que.pop();
            for(int i = head[now]; i != -1; i = edges[i].next){
                int v = edges[i].to;
                indegree[v] -= 1;
                if(indegree[v] == 0){
                    que.push(v);
                    ret.push_back(v);
                }
            }
        }
        for(int i = 0; i < numCourses; ++i){
            if(indegree[i] != 0){
                ret.clear();
                break;
            }
        }
        return ret;
    }
};

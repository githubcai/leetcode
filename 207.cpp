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
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<Edge> edges;
        vector<int> indegree(numCourses, 0), head(numCourses, -1);
        int size = prerequisites.size();
        for(int i = 0; i < size; ++i){
            auto temp = prerequisites[i];
            indegree[temp.first] += 1;
            addEdge(temp.second, temp.first, edges, head);
        }
        queue<int> que;
        for(int i = 0; i < numCourses; ++i){
            if(indegree[i] == 0) que.push(i);
        }
        while(!que.empty()){
            int now = que.front();
            que.pop();
            for(int i = head[now]; i != -1; i = edges[i].next){
                int v = edges[i].to;
                indegree[v] -= 1;
                if(indegree[v] == 0) que.push(v);
            }
        }
        for(int i = 0; i < numCourses; ++i){
            if(indegree[i] != 0) return false;
        }
        return true;
    }
};

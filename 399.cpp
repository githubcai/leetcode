class Solution {
    struct Edge{
        int to, next;
        double w;
    };
    vector<Edge> edges;
    vector<int> head;
    unordered_map<string, int> ref;
    
    void addEdge(int from, int to, double w){
        Edge e = {to, head[from], w};
        head[from] = edges.size();
        edges.push_back(e);
    }
    
    bool dfs(int from, int to, int pre, double &w){
        if(from == to) return true;
        for(int i = head[from]; i != -1; i = edges[i].next){
            int v = edges[i].to;
            if(v == pre) continue;
            double temp = w * edges[i].w;
            if(dfs(v, to, from, temp)){
                w = temp;
                return true;
            }
        }
        return false;
    }
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        int cnt = 0;
        head.clear(); edges.clear(); ref.clear();
        for(int i = 0; i < equations.size(); ++i){
            if(ref.find(equations[i].first) == ref.end()){
                ref[equations[i].first] = cnt++;
                head.push_back(-1);
            }
            if(ref.find(equations[i].second) == ref.end()){
                ref[equations[i].second] = cnt++;
                head.push_back(-1);
            }
            addEdge(ref[equations[i].first], ref[equations[i].second], values[i]);
            addEdge(ref[equations[i].second], ref[equations[i].first], 1.0 / values[i]);
        }
        vector<double> ret;
        for(auto iter = queries.begin(); iter != queries.end(); ++iter){
            if(ref.find(iter->first) == ref.end() || ref.find(iter->second) == ref.end()){
                ret.push_back(-1.0);
            }else{
                double temp = 1.0;
                bool flag = dfs(ref[iter->first], ref[iter->second], -1, temp);
                if(flag){
                    ret.push_back(temp);
                }else{
                    ret.push_back(-1.0);
                }
            }
        }
        return ret;
    }
};

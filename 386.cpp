class Solution {
    void dfs(int num, int n, vector<int> &ret){
        for(int i = 0; i < 10; ++i){
            int temp = num * 10 + i;
            if(temp > n) return;
            ret.push_back(temp);
            dfs(temp, n, ret);
        }
    }
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ret;
        for(int i = 1; i < 10; ++i){
            if(i > n) break;
            ret.push_back(i);
            dfs(i, n, ret);
        }
        return ret;
    }
};

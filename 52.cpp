class Solution {
    int ret, total;
    
    void dfs(const vector<int> &pos){
        if(pos.size() == total){
            ret += 1;
            return;
        }
        for(int i = 0; i < total; ++i){
            bool flag = true;;
            for(int j = 0; j < pos.size(); ++j){
                if(pos[j] == i || fabs(pos.size() - j) == fabs(i - pos[j])){
                    flag = false;
                    break;
                }
            }
            if(flag){
                vector<int> tpos;
                copy(pos.begin(), pos.end(), back_inserter(tpos));
                tpos.push_back(i);
                dfs(tpos);
            }
        }
    }
    
public:
    int totalNQueens(int n) {
        ret = 0;
        total = n;
        vector<int> pos;
        dfs(pos);
        return ret;
    }
};

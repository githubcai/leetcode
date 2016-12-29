class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int ret = 0;
        map<int, int> first, second;
        for(int i = 0; i < A.size(); ++i){
            for(int j = 0; j < B.size(); ++j){
                first[A[i] + B[j]] += 1;
            }
        }
        for(int i = 0; i < C.size(); ++i){
            for(int j = 0; j < D.size(); ++j){
                second[-C[i] - D[j]] += 1;
            }
        }
        for(auto f = first.begin(), s = second.begin(); f != first.end() && s != second.end();){
            if(f->first > s->first){
                ++s;
            }else if(f->first < s->first){
                ++f;
            }else{
                ret += f->second * s->second;
                ++f, ++s;
            }
        }
        return ret;
    }
};

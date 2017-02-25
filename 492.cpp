class Solution {
public:
    vector<int> constructRectangle(int area) {
        int L = ceil(sqrt(area)), W;
        while(L <= area){
            if(area % L == 0){
                W = area / L;
                break;
            }
            L += 1;
        }
        vector<int> ret;
        ret.push_back(L);
        ret.push_back(W);
        return ret;
    }
};

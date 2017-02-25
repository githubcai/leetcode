class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ret = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        for(int i = 0, j = 0; i < g.size() && j < s.size();){
            if(s[j] >= g[i]){
                ret += 1;
                i += 1;
                j += 1;
            }else{
                j += 1;
            }
        }
        return ret;
    }
};

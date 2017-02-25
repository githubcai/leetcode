class Solution {
public:
    int maxProduct(vector<string>& words) {
        int size = words.size();
        vector<int> length(size, 0), mask(size, 0);
        for(int i = 0; i < size; ++i){
            length[i] = words[i].size();
            for(int j = 0; j < length[i]; ++j) mask[i] |= (1 << (words[i][j] - 'a'));
        }
        int ret = 0;
        for(int i = 0; i < size; ++i){
            for(int j = i + 1; j < size; ++j){
                if((mask[i] & mask[j]) == 0){
                    if(ret < length[i] * length[j]) ret = length[i] * length[j];
                }
            }
        }
        return ret;
    }
};

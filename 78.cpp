class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        ret.push_back(vector<int>());
        for(auto iter = nums.begin(); iter != nums.end(); ++iter){
            int lmt = ret.size();
            for(int i = 0; i < lmt; ++i){
                vector<int> temp = ret[i];
                temp.push_back(*iter);
                ret.push_back(temp);
            }
        }
        return ret;
    }
};

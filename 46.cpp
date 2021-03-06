class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size() <= 1){
            ans.push_back(nums);
            return ans;
        }
        for(int i = 0; i < nums.size(); ++i){
            vector<int> temp;
            for(int j = 0; j < nums.size(); ++j){
                if(i != j) temp.push_back(nums[j]);
            }
            vector<vector<int>> tans = permute(temp);
            for(int j = 0; j < tans.size(); ++j){
                tans[j].push_back(nums[i]);
                ans.push_back(tans[j]);
            }
        }
        return ans;
    }
};

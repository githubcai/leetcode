class Solution {
    string getStr(int st, int ed){
        string ret, temp;
        stringstream ss;
        ss << st; ss >> ret;
        if(st != ed){
            ret += "->";
            ss.clear();
            ss << ed; ss >> temp;
            ret += temp;
        }
        return ret;
    }
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        int size = nums.size();
        if(size == 0) return ret;
        int st = nums[0];
        for(int i = 1; i < size; ++i){
            if(nums[i] != nums[i - 1] + 1){
                ret.push_back(getStr(st, nums[i - 1]));
                st = nums[i];
            }
        }
        ret.push_back(getStr(st, nums[size - 1]));
        return ret;
    }
};

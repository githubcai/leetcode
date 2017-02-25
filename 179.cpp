class Solution {
    static bool cmp(const string &a, const string &b){
        return a + b > b + a;
    }
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strVec(nums.size());
        for(int i = 0; i < nums.size(); ++i){
            stringstream ss;
            ss << nums[i];
            ss >> strVec[i];
        }
        sort(strVec.begin(), strVec.end(), cmp);
        string ret;
        for(int i = 0; i < strVec.size(); ++i){
            ret += strVec[i];
        }
        int ind;
        for(ind = 0; ind < ret.size(); ++ind){
            if(ret[ind] != '0') break;
        }
        if(ind == ret.size()){
            ret = "0";
        }else if(ind > 0){
            ret = ret.substr(ind);
        }
        return ret;
    }
};

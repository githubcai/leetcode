class Solution {
    void dfs(string num, long long target, long long sum, long long diff, string sRet, vector<string> &ret){
        if(num.size() == 0){
            if(sum == target) ret.push_back(sRet);
            return;
        }
        for(int i = 1; i <= num.size(); ++i){
            string str = num.substr(0, i);
            if(str.size() > 1 && str[0] == '0') return;
            string temp = num.substr(i);
            long long t = stoll(str);
            if(sRet.size() > 0){
                dfs(temp, target, sum + t, t, sRet + "+" + str, ret);
                dfs(temp, target, sum - t, -t, sRet + "-" + str, ret);
                dfs(temp, target, (sum - diff) + diff * t, diff * t, sRet + "*" + str, ret);
            }else{
                dfs(temp, target, sum + t, t, str, ret);
            }
        }
    }
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ret;
        dfs(num, (long long)target, 0L, 0L, "", ret);
        return ret;
    }
};

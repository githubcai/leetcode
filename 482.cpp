class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string str, ret;
        for(auto iter = S.rbegin(); iter != S.rend(); ++iter){
            if(*iter != '-'){
                if(*iter >= 'a' && *iter <= 'z'){
                    str += string(1, *iter - 'a' + 'A');
                }else{
                    str += string(1, *iter);
                }
            }
        }
        int ind = 0;
        if(str.size() <= K){
            ret = str;
        }else{
            ret += str.substr(ind, K);
            ind += K;
            while(ind + K <= str.size()){
                ret += "-";
                ret += str.substr(ind, K);
                ind += K;
            }
            if(ind < str.size()){
                ret += "-";
                ret += str.substr(ind);
            }
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

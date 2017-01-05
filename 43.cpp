class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> n1, n2;
        for(int i = num1.size() - 1; i >= 0;){
            int temp = 0, fac = 1;
            for(int j = 0; j < 4 && i >= 0; ++j){
                temp += (num1[i] - '0') * fac;
                i -= 1;
                fac *= 10;
            }
            n1.push_back(temp);
        }
        for(int i = num2.size() - 1; i >= 0;){
            int temp = 0, fac = 1;
            for(int j = 0; j < 4 && i >= 0; ++j){
                temp += (num2[i] - '0') * fac;
                i -= 1;
                fac *= 10;
            }
            n2.push_back(temp);
        }
        vector<int> ret;
        for(int i = 0; i < n2.size(); ++i){
            int c = 0;
            for(int j = 0; j < n1.size(); ++j){
                int temp;
                if(i + j >= ret.size()){
                    temp = 0;
                }else{
                    temp = ret[i + j];
                }
                temp += n1[j] * n2[i] + c;
                c = temp / 10000;
                if(i + j >= ret.size()){
                    ret.push_back(temp % 10000);
                }else{
                    ret[i + j] = temp % 10000;
                }
            }
            if(c != 0) ret.push_back(c);
        }
        string ans;
        int lmt;
        for(lmt = ret.size() - 1; lmt >= 0 && ret[lmt] == 0; --lmt);
        for(int i = 0; i < lmt; ++i){
            for(int j = 0; j < 4; ++j){
                int temp = ret[i] % 10;
                ret[i] /= 10;
                ans += temp + '0';
            }
        }
        while(ret[lmt] > 0){
            int temp = ret[lmt] % 10;
            ans += temp + '0';
            ret[lmt] /= 10;
        }
        reverse(ans.begin(), ans.end());
        if(ans == "") ans = "0";
        return ans;
    }
};

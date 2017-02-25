class Solution {
public:
    string decodeString(string s) {
        string ret;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] >= '0' && s[i] <= '9'){
                int temp = s[i++] - '0';
                while(s[i] >= '0' && s[i] <= '9'){
                    temp = 10 * temp + s[i] - '0';
                    i += 1;
                }
                int flag = 1;
                string str;
                while(flag != 0){
                    i += 1;
                    if(s[i] == ']'){
                        flag -= 1;
                        if(flag != 0) str += "]";
                    }else{
                        str += string(1, s[i]);
                        if(s[i] == '[') flag += 1;
                    }
                }
                str = decodeString(str);
                while(temp-- > 0) ret += str;
            }else{
                ret += string(1, s[i]);
            }
        }
        return ret;
    }
};

class Solution {
public:
    int calculate(string s) {
        string str;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] != ' ') str += string(1, s[i]);
        }
        int ret = 0, diff = 0;
        char oper = '+';
        for(int i = 0; i < str.size();){
            int temp = 0;
            if(!isdigit(str[i])){
                oper = str[i++];
            }else{
                while(i < str.size() && isdigit(str[i])){
                    temp = temp * 10 + str[i] - '0';
                    i += 1;
                }
                switch(oper){
                    case '+':
                        ret += temp;
                        diff = temp;
                        break;
                    case '-':
                        ret -= temp;
                        diff = -temp;
                        break;
                    case '*':
                        ret = (ret - diff) + diff * temp;
                        diff = diff * temp;
                        break;
                    case '/':
                        ret = (ret - diff) + diff / temp;
                        diff = diff / temp;
                        break;
                }
            }
        }
        return ret;
    }
};

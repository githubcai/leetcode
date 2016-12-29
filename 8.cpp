class Solution {
public:
    int myAtoi(string str) {
        int index = 0, ed = str.size();
        while(str[index] == ' ') ++index;
        if(str.size() == index || (str.size() == index + 1 && (str[index] < '0' || str[index] > '9'))) return 0;
        if(str[index] != '+' && str[index] != '-' && (str[index] < '0' || str[index] > '9')) return 0;
        for(int i = index + 1; i < str.size(); ++i){
            if(str[i] < '0' || str[i] > '9'){
                ed = i;
                break;
            }
        }
        long long ret = 0;
        int neg = 1;
        if(str[index] == '+'){
            index += 1;
        }else if(str[index] == '-'){
            index += 1;
            neg = -1;
        }
        for(int i = index; i < ed; ++i){
            ret = ret * 10 + (str[i] - '0') * neg;
            if(ret > INT_MAX) return INT_MAX;
            if(ret < INT_MIN) return INT_MIN;
        }
        return ret;
    }
};

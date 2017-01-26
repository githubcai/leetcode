class Solution {
public:
    bool isNumber(string s) {
        int index = 0, lmt = s.size();
        while(index < lmt && s[index] == ' ') index += 1;
        while(index < lmt && s[lmt - 1] == ' ') lmt -= 1;
        if(index == lmt || (s[index] != '.' && s[index] != '+' && s[index] != '-' && !(s[index] >= '0' && s[index] <= '9'))) return false;
        if(s[index] == '+' || s[index] == '-') index += 1;
        if(index == lmt) return false;
        int flag = 0;
        bool has_num = false;
        while(index < lmt){
            if(s[index] >= '0' && s[index] <= '9'){
                index += 1;
                has_num = true;
            }else if(s[index] == 'e'){
                index += 1;
                flag = 1;
                break;
            }else if(s[index] == '.'){
                index += 1;
                flag = 2;
                break;
            }else{
                return false;
            }
        }
        if(flag == 1){
            if(index == lmt || !has_num) return false;
            if(s[index] == '-' || s[index] == '+') index += 1;
            if(index == lmt) return false;
            while(index < lmt){
                if(s[index] < '0' || s[index] > '9') return false;
                index += 1;
            }
        }else if(flag == 2){
            if(!has_num && (index == lmt || s[index] < '0' || s[index] > '9')) return false;
            while(index < lmt){
                if(s[index] == 'e'){
                    index += 1;
                    if(index == lmt) return false;
                    if(s[index] == '-' || s[index] == '+') index += 1;
                    if(index == lmt) return false;
                    while(index < lmt){
                        if(s[index] < '0' || s[index] > '9') return false;
                        index += 1;
                    }
                }else{
                    if(s[index] < '0' || s[index] > '9')  return false;
                    index += 1;
                }
            }
        }
        return true;
    }
};

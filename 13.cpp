class Solution {
public:
    int romanToInt(string s) {
        int ret = 0;
        for(int i = 0; i < s.size();){
            switch(s[i]){
                case 'I':
                    if(s[i + 1] == 'V'){
                        ret += 4;
                        i += 2;
                    }else if(s[i + 1] == 'X'){
                        ret += 9;
                        i += 2;
                    }else{
                        ret += 1;
                        i += 1;
                        while(i < s.size() && s[i] == 'I') ret += 1, ++i;
                    }
                    break;
                case 'V':
                    if(s[i + 1] == 'I'){
                        ret += 6;
                        i += 2;
                        while(i < s.size() && s[i] == 'I') ret += 1, ++i;
                    }else{
                        ret += 5;
                        i += 1;
                    }
                    break;
                case 'X':
                    if(s[i + 1] == 'L'){
                        ret += 40;
                        i += 2;
                    }else if(s[i + 1] == 'C'){
                        ret += 90;
                        i += 2;
                    }else{
                        ret += 10;
                        i += 1;
                        while(i < s.size() && s[i] == 'X') ret += 10, ++i;
                    }
                    break;
                case 'L':
                    if(s[i + 1] == 'X'){
                        ret += 60;
                        i += 2;
                        while(i < s.size() && s[i] == 'X') ret += 10, ++i;
                    }else{
                        ret += 50;
                        i += 1;
                    }
                    break;
                case 'C':
                    if(s[i + 1] == 'D'){
                        ret += 400;
                        i += 2;
                    }else if(s[i + 1] == 'M'){
                        ret += 900;
                        i += 2;
                    }else{
                        ret += 100;
                        i += 1;
                        while(i < s.size() && s[i] == 'C') ret += 100, ++i;
                    }
                    break;
                case 'D':
                    if(s[i + 1] == 'C'){
                        ret += 600;
                        i += 2;
                        while(i < s.size() && s[i] == 'C') ret += 100, ++i;
                    }else{
                        ret += 500;
                        i += 1;
                    }
                    break;
                case 'M':
                    ret += 1000;
                    i += 1;
                    while(i < s.size() && s[i] == 'M') ret += 1000, ++i;
                    break;
            }
        }
        return ret;
    }
};

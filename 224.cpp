class Solution {
    char getPri(char oper1, char oper2){
        char pri[5][6] = {
            "<<><>",
            "<<><>",
            ">>>=>",
            "<<=<>",
            "<<<<="
        };
        int n1, n2;
        switch(oper1){
            case '+': n1 = 0; break;
            case '-': n1 = 1; break;
            case '(': n1 = 2; break;
            case ')': n1 = 3; break;
            case '#': n1 = 4; break;
        }
        switch(oper2){
            case '+': n2 = 0; break;
            case '-': n2 = 1; break;
            case '(': n2 = 2; break;
            case ')': n2 = 3; break;
            case '#': n2 = 4; break;
        }
        return pri[n1][n2];
    }
    int cal(int num1, char oper, int num2){
        int ret = 0;
        switch(oper){
            case '+': ret = num1 + num2; break;
            case '-': ret = num1 - num2; break;
        }
        return ret;
    }
public:
    int calculate(string s) {
        stack<int> num;
        stack<char> oper;
        s += '#';
        oper.push('#');
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == ' ') continue;
            if(isdigit(s[i])){
                int temp = s[i++] - '0';
                while(isdigit(s[i])) temp = 10 * temp + (s[i++] - '0');
                i -= 1;
                num.push(temp);
            }else{
                char operRet = getPri(s[i], oper.top());
                if(operRet == '<'){
                    char c = oper.top(); oper.pop();
                    int num1 = num.top(); num.pop();
                    int num2 = num.top(); num.pop();
                    num.push(cal(num2, c, num1));
                    i -= 1;
                }else if(operRet == '>'){
                    oper.push(s[i]);
                }else{
                    oper.pop();
                }
            }
        }
        return num.top();
    }
};

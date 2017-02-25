class Solution {
    int cal(int num1, char oper, int num2){
        int ret = 0;
        switch(oper){
            case '+': ret = num1 + num2; break;
            case '-': ret = num1 - num2; break;
            case '*': ret = num1 * num2; break;
            case '/': ret = num1 / num2; break;
        }
        return ret;
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(int i = 0; i < tokens.size(); ++i){
            if(tokens[i].size() > 1 || isdigit(tokens[i][0])){
                stringstream ss;
                ss << tokens[i];
                int temp; ss >> temp;
                stk.push(temp);
            }else{
                int num1, num2;
                num2 = stk.top(); stk.pop();
                num1 = stk.top(); stk.pop();
                stk.push(cal(num1, tokens[i][0], num2));
            }
        }
        return stk.top();
    }
};

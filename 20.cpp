class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(int i = 0; i < s.size(); ++i){
            if(stk.empty()){
                stk.push(s[i]);
            }else{
                if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                    stk.push(s[i]);
                }else{
                    if((s[i] == ')' && stk.top() != '(') || (s[i] == ']' && stk.top() != '[') || (s[i] == '}' && stk.top() != '{')) return false;
                    stk.pop();
                }
            }
        }
        if(!stk.empty()) return false;
        return true;
    }
};

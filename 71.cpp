class Solution {
public:
    string simplifyPath(string path) {
        path += '/';
        int plen = path.size();
        if(plen == 1) return path;
        stack<char> stk;
        stk.push(path[0]);
        for(int i = 1; i < plen; ++i){
            if(path[i] == '/'){
                if(!stk.empty()){
                    if(stk.top() == '.'){
                        stk.pop();
                        if(!stk.empty()){
                            if(stk.top() == '.'){
                                stk.pop();
                                if(!stk.empty()){
                                    if(stk.top() == '/'){
                                        stk.pop();
                                        while(!stk.empty()){
                                            if(stk.top() == '/') break;
                                            stk.pop();
                                        }
                                        if(stk.empty()) stk.push('/');
                                    }else{
                                        stk.push('.');
                                        stk.push('.');
                                        stk.push('/');
                                    }
                                }else{
                                    stk.push('/');
                                }
                            }
                        }else{
                            stk.push('/');
                        }
                    }else if(stk.top() == '/'){
                        continue;
                    }else{
                        stk.push(path[i]);
                    }
                }else{
                    stk.push(path[i]);
                }
            }else{
                stk.push(path[i]);
            }
        }
        while(!stk.empty() && stk.top() == '/') stk.pop();
        if(stk.empty()) stk.push('/');
        string ret;
        while(!stk.empty()){
            ret += stk.top();
            stk.pop();
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

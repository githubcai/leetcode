class Solution {
    int cal(int a, char oper, int b){
        int ret;
        switch(oper){
            case '+':
                ret = a + b;
                break;
            case '-':
                ret = a - b;
                break;
            case '*':
                ret = a * b;
                break;
        }
        return ret;
    }
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> ret;
        int ind;
        for(ind = 0; ind < input.size(); ++ind){
            if(!isdigit(input[ind])) break;
        }
        if(ind == input.size()){
            stringstream ss;
            ss << input;
            int temp; ss >> temp;
            ret.push_back(temp);
            return ret;
        }
        for(;ind < input.size(); ++ind){
            if(isdigit(input[ind])) continue;
            string lStr = input.substr(0, ind), rStr = input.substr(ind + 1, input.size() - ind);
            vector<int> t1 = diffWaysToCompute(lStr), t2 = diffWaysToCompute(rStr);
            for(int i = 0; i < t1.size(); ++i){
                for(int j = 0 ; j < t2.size(); ++j){
                    int temp = cal(t1[i], input[ind], t2[j]);
                    ret.push_back(temp);
                }
            }
        }
        return ret;
    }
};

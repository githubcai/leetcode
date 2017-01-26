class Solution {
    int getMax(const vector<int> &inp){
        stack<int> stk;
        int ret = 0;
        for(int i = 0; i < inp.size(); ++i){
            int cnt = 1;
            while(!stk.empty() && stk.top() > inp[i]){
                int temp = cnt * stk.top();
                if(temp > ret) ret = temp;
                stk.pop();
                cnt += 1;
            }
            for(int j = 0; j < cnt; ++j) stk.push(inp[i]);
        }
        int cnt = 1;
        while(!stk.empty()){
            int temp = cnt * stk.top();
            stk.pop();
            cnt += 1;
            if(temp > ret) ret = temp;
        }
        return ret;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0) return 0;
        vector<int> inp(matrix[0].size(), 0);
        int ans = 0;
        for(int i = 0; i < matrix.size(); ++i){
            for(int j = 0; j < matrix[0].size(); ++j){
                if(matrix[i][j] == '1'){
                    inp[j] += 1;
                }else{
                    inp[j] = 0;
                }
            }
            int temp = getMax(inp);
            if(ans < temp) ans = temp;
        }
        return ans;
    }
};

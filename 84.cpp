class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size() == 0) return 0;
        stack<int> stk;
        stk.push(heights[0]);
        int ans = heights[0];
        for(int i = 1; i < heights.size(); ++i){
            if(stk.top() <= heights[i]){
                stk.push(heights[i]);
            }else{
                int cnt = 1;
                while(!stk.empty() && stk.top() >= heights[i]){
                    int temp = stk.top() * cnt;
                    cnt += 1;
                    stk.pop();
                    if(temp > ans) ans = temp;
                }
                for(int j = 0; j < cnt; ++j) stk.push(heights[i]);
            }
        }
        int cnt = 1;
        while(!stk.empty()){
            int temp = stk.top() * cnt;
            stk.pop();
            cnt += 1;
            if(temp > ans) ans = temp;
        }
        return ans;
    }
};

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int size = A.size(), ret = 0;
        if(size < 3) return 0;
        vector<int> dp(size, 0);
        int pre = A[1] - A[0];
        for(int i = 2; i < size; ++i){
            int temp = A[i] - A[i - 1];
            if(temp == pre) dp[i] = dp[i - 1] + 1;
            pre = temp;
            ret += dp[i];
        }
        return ret;
    }
};

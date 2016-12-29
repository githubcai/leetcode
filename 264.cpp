class Solution {
public:
    int nthUglyNumber(int n) {
        int dp[n] = {1}, p2 = 0, p3 = 0, p5 = 0, min2 = 2, min3 = 3, min5 = 5;
        for(int i = 1; i < n; ++i){
            dp[i] = min(min2, min(min3, min5));
            if(min2 == dp[i]) min2 = dp[++p2] * 2;
            if(min3 == dp[i]) min3 = dp[++p3] * 3;
            if(min5 == dp[i]) min5 = dp[++p5] * 5;
        }
        return dp[n - 1];
    }
};

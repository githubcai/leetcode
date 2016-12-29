class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int dp[n] = {1};
        vector<int> minN, pN;
        for(int i = 0; i < primes.size(); ++i){
            minN.push_back(primes[i]);
            pN.push_back(0);
        }
        for(int i = 1; i < n; ++i){
            int mn = INT_MAX;
            for(int j = 0; j < minN.size(); ++j){
                if(mn > minN[j]) mn = minN[j];
            }
            dp[i] = mn;
            for(int j = 0; j < minN.size(); ++j){
                long long t1 = dp[pN[j] + 1], t2 = primes[j];
                long long temp = t1 * t2;
                if(temp > INT_MAX) temp = INT_MAX;
                if(minN[j] == mn) minN[j] = temp, pN[j] += 1;
            }
        }
        return dp[n - 1];
    }
};

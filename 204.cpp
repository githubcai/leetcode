class Solution {
public:
    int countPrimes(int n) {
        bool isPrime[n];
        vector<int> prime;
        for(int i = 2; i < n; ++i) isPrime[i] = true;
        int ret = 0;
        for(int i = 2; i < n; ++i){
            if(isPrime[i]){
                ret += 1;
                prime.push_back(i);
            }
            for(int j = 0; j < prime.size(); ++j){
                if(i * prime[j] >= n) break;;
                isPrime[i * prime[j]] = false;
                if(i % prime[j] == 0) break;
            }
        }
        return ret;
    }
};

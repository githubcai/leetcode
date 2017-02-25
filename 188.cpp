class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int size = prices.size();
        if(size < 2 || k == 0) return 0;
        if(k >= size / 2){
            int ret = 0;
            for(int i = 1; i < size; ++i){
                int temp = prices[i] - prices[i - 1];
                if(temp > 0) ret += temp;
            }
            return ret;
        }
        int local[k + 1], global[k + 1];
        memset(local, 0, sizeof(local));
        memset(global, 0, sizeof(global));
        for(int i = 1; i < size; ++i){
            int diff = prices[i] - prices[i - 1];
            for(int j = k; j > 0; --j){
                local[j] = max(global[j - 1], local[j]) + diff;
                global[j] = max(global[j], local[j]);
            }
        }
        return global[k];
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices){
        int size = prices.size();
        if(size < 2) return 0;
        int pre[size], post[size];
        pre[0] = 0;
        int minP = prices[0];
        for(int i = 1; i < size; ++i){
            int temp = prices[i] - minP;
            pre[i] = max(pre[i - 1], temp);
            if(prices[i] < minP) minP = prices[i];
        }
        post[size - 1] = 0;
        int maxP = prices[size - 1];
        for(int i = size - 2; i >= 0; --i){
            int temp = maxP - prices[i];
            post[i] = max(post[i + 1], temp);
            if(prices[i] > maxP) maxP = prices[i];
        }
        int ret = 0;
        for(int i = 0; i < size; ++i){
            int temp =  pre[i] + post[i];
            if(ret < temp) ret = temp;
        }
        return ret;
    }
};

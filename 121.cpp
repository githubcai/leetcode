class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        int ret = 0, mn = prices[0];
        for(int i = 1; i < prices.size(); ++i){
            if(prices[i] < mn){
                mn = prices[i];
            }else{
                int temp = prices[i] - mn;
                if(temp > ret) ret = temp;
            }
        }
        return ret;
    }
};

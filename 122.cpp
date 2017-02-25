class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ret = 0, ind, low;
        for(ind = 1; ind < prices.size(); ++ind){
            if(prices[ind] != prices[ind - 1]) break;
        }
        if(ind >= prices.size()) return ret;
        bool flag = true;
        if(prices[ind] > prices[ind - 1]){
            low = prices[ind - 1];
            flag = false;
        }
        for(; ind < prices.size(); ++ind){
            if(flag){
                if(prices[ind] > prices[ind - 1]){
                    low = prices[ind - 1];
                    flag = false;
                }
            }else{
                if(prices[ind] < prices[ind - 1]){
                    ret += prices[ind - 1] - low;
                    flag = true;
                }
            }
        }
        if(!flag) ret += prices[ind - 1] - low;
        return ret;
    }
};

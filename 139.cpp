class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int size = s.size();
        bool dp[size + 1];
        memset(dp, 0, sizeof(dp));
        dp[0] = true;
        for(int i = 1; i <= size; ++i){
            for(int j = 0; j <= i; ++j){
                if(dp[j]){
                    string temp = s.substr(j, i - j);
                    bool flag = false;
                    for(auto iter = wordDict.begin(); iter != wordDict.end(); ++iter){
                        if(*iter == temp){
                            flag = true;
                            break;
                        }
                    }
                    if(flag){
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[size];
    }
};

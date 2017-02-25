class Solution {
public:
    int characterReplacement(string s, int k) {
        int ret = 0, st = 0, mx = 0;
        vector<int> cnt(26, 0);
        for(int i = 0; i < s.size(); ++i){
            cnt[s[i] - 'A'] += 1;
            if(cnt[s[i] - 'A'] > mx) mx = cnt[s[i] - 'A'];
            while(i - st + 1 - mx > k){
                cnt[s[st] - 'A'] -= 1;
                st += 1;
            }
            ret = max(ret, i - st + 1);
        }
        return ret;
    }
};

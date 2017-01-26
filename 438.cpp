class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ret;
        vector<int> cnt(26, 0), pcnt(26, 0);
        for(int i = 0; i < p.size(); ++i) cnt[p[i] - 'a'] += 1;
        int left = 0;
        for(int i = 0; i < s.size(); ++i){
            if(cnt[s[i] - 'a'] == 0){
                pcnt.assign(26, 0);
                left = i + 1;
                continue;
            }
            pcnt[s[i] - 'a'] += 1;
            while(pcnt[s[i] - 'a'] > cnt[s[i] - 'a']){
                pcnt[s[left] - 'a'] -= 1;
                left += 1;
            }
            if(i - left + 1 == p.size()){
                ret.push_back(left);
                pcnt[s[left] - 'a'] -= 1;
                left += 1;
            }
        }
        
        return ret;
    }
};

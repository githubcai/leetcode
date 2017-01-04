class Solution {
public:
    string minWindow(string s, string t) {
        int sl = s.size(), tl = t.size();
        if(sl <= 0 || tl <= 0) return "";
        vector<int> store(128, 0), tst(128, 0);
        for(int i = 0; i < t.size(); ++i) store[t[i]] += 1;
        int cnt = 0, left = 0;
        string ans = "";
        for(int i = 0; i < sl; ++i){
            if(store[s[i]] > 0){
                if(tst[s[i]] < store[s[i]]) cnt += 1;
                tst[s[i]] += 1;
                while(cnt == tl){
                    int temp = i - left + 1;
                    if(ans == "" || temp < ans.size()){
                        ans = s.substr(left, temp);
                    }
                    if(tst[s[left]] > 0){
                        tst[s[left]] -= 1;
                        if(tst[s[left]] < store[s[left]]) cnt -= 1;
                    }
                    left += 1;
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int sl = s.size(), wsl = words.size();
        if(sl <= 0 || wsl <= 0) return ans;
        unordered_map<string, int> dict;
        for(int i = 0; i < wsl; ++i) dict[words[i]] += 1;
        int wl = words[0].size();
        for(int i = 0; i < wl; i += 1){
            int left = i, cnt = 0;
            unordered_map<string, int> tdict;
            for(int j = i; j <= sl - wl; j += wl){
                string word = s.substr(j, wl);
                if(dict[word] > 0){
                    tdict[word] += 1;
                    cnt += 1;
                    if(tdict[word] > dict[word]){
                        while(tdict[word] > dict[word]){
                            string str = s.substr(left, wl);
                            tdict[str] -= 1;
                            cnt -= 1;
                            left += wl;
                        }
                    }
                    if(cnt == wsl){
                        ans.push_back(left);
                        string str = s.substr(left, wl);
                        tdict[str] -= 1;
                        cnt -= 1;
                        left += wl;
                    }
                }else{
                    tdict.clear();
                    cnt = 0;
                    left = j + wl;
                }
            }
        }
        return ans;
    }
};

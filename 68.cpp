class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ret;
        int wlen = words.size();
        if(wlen == 0) return ret;
        vector<int> lwords;
        for(int i = 0; i < wlen; ++i) lwords.push_back(words[i].size());
        int l = lwords[0], st = 0;
        for(int i = 1; i < wlen; ++i){
            l += lwords[i] + 1;
            if(l > maxWidth){
                l = l - 1 - lwords[i];
                int spCnt = 0, fspCnt, cnt = i - st - 1;
                string temp = words[st];
                if(cnt != 0){
                    spCnt = (maxWidth - l) / cnt;
                    fspCnt = maxWidth - (l + spCnt * cnt);
                    string sSp(spCnt, ' ');
                    for(int j = st + 1; j < i; ++j){
                        string Fsp = "";
                        if(fspCnt > 0){
                            fspCnt -= 1;
                            Fsp = " ";
                        }
                        temp += sSp + ' ' + Fsp + words[j];
                    }
                }else{
                    string sSp(maxWidth - l, ' ');
                    temp += sSp;
                }
                ret.push_back(temp);
                st = i;
                l = lwords[i];
            }
        }
        if(st < wlen){
            string temp = words[st];
            for(int i = st + 1; i < wlen; ++i){
                temp += " " + words[i];
            }
            string sSp(maxWidth - l, ' ');
            temp += sSp;
            ret.push_back(temp);
        }
        return ret;
    }
};

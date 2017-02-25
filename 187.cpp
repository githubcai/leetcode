class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int size = s.size();
        vector<string> ret;
        if(size < 11) return ret;
        unordered_map<int, int> ref;
        int freq = 0, temp = 0;
        for(int i = 0; i < size; ++i){
            switch(s[i]){
                case 'T': temp += 0; break;
                case 'A': temp += 1; break;
                case 'C': temp += 2; break;
                case 'G': temp += 3; break;
            }
            freq += 1;
            if(freq == 10){
                ref[temp] += 1;
                temp &= 0x3ffff;
                freq -= 1;
            }
            temp <<= 2;
        }
        for(auto iter = ref.begin(); iter != ref.end(); ++iter){
            if(iter->second > 1){
                int temp = (3 << 18);
                string str;
                int move = 18;
                while(temp > 0){
                    int t = ((iter->first & temp) >> move);
                    switch(t){
                        case 0: str += "T"; break;
                        case 1: str += "A"; break;
                        case 2: str += "C"; break;
                        case 3: str += "G"; break;
                    }
                    temp >>= 2;
                    move -= 2;
                }
                ret.push_back(str);
            }
        }
        return ret;
    }
};

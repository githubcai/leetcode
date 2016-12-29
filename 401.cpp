class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> ret;
        if(num < 0 && num > 9) return ret;
        if(num == 0){
            ret.push_back("0:00");
            return ret;
        }
        for(int h = 0; h < 12; ++h){
            for(int m = 0; m < 60; ++m){
                int temp = m;
                temp = ((temp << 4) | h);
                int cnt = 0;
                while(temp > 0){
                    if((temp & 1) == 1) cnt += 1;
                    temp >>= 1;
                }
                if(cnt == num){
                    stringstream ss;
                    string str, temp;
                    ss << h; ss >> temp; str += temp + ":";
                    ss.clear();
                    if(m < 10) str += "0";
                    ss << m; ss >> temp; str += temp;
                    ret.push_back(str);
                }
            }
        }
        return ret;
    }
};

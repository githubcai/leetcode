class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long long num1 = numerator, num2 = denominator;
        string ret, str;
        if(num1 * num2 < 0) ret = "-";
        if(num1 < 0) num1 = -num1;
        if(num2 < 0) num2 = -num2;
        long long temp = num1 / num2;
        stringstream ss;
        ss << temp;
        ss >> str;
        ret += str;
        num1 %= num2;
        if(num1 != 0) ret += ".";
        string strRes;
        unordered_map<int, int> ref;
        int cnt = 0;
        while(num1 != 0){
            temp = num1 * 10 / num2;
            if(ref.find(num1) != ref.end()){
                str = strRes.substr(0, ref[num1]);
                str += "(";
                str += strRes.substr(ref[num1], strRes.size() - ref[num1]);
                str += ")";
                strRes = str;
                break;
            }
            ref[num1] = cnt++;
            ss.clear();
            ss << temp;
            ss >> str;
            strRes += str;
            num1 = num1 * 10 % num2;
        }
        ret += strRes;
        return ret;
    }
};


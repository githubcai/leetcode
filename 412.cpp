class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ret;
        for(int i = 1; i <= n; ++i){
            string temp;
            int t3 = i % 3, t5 = i % 5;
            if(t3 == 0) temp += "Fizz";
            if(t5 == 0) temp += "Buzz";
            if(t3 != 0 && t5 != 0){
                stringstream ss;
                ss << i;
                ss >> temp;
            }
            ret.push_back(temp);
        }
        return ret;
    }
};

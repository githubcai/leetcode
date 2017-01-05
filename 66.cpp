class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ret;
        int c = 0;
        digits[digits.size() - 1] += 1;
        for(int i = digits.size() - 1; i >= 0; --i){
            int temp = digits[i] + c;
            c = temp / 10;
            ret.push_back(temp % 10);
        }
        if(c != 0) ret.push_back(c);
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

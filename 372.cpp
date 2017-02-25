class Solution {
public:
    int superPow(int a, vector<int>& b) {
        long long ret = 1;
        if(b.size() == 0) return (int)ret;
        for(int i = 0; i < b.front(); ++i) ret = ret * a % 1337;
        if(b.size() == 1) return (int)ret;
        for(auto iter = b.begin() + 1; iter != b.end(); ++iter){
            int temp = ret;
            ret = 1;
            for(int i = 0; i < 10; ++i) ret = ret * temp % 1337;
            for(int i = 0; i < *iter; ++i) ret = ret * a % 1337;
        }
        return (int)ret;
    }
};

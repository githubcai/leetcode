class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> ref;
        while(n != 1){
            if(ref.find(n) == ref.end()){
                ref.insert(n);
                int temp = n;
                n = 0;
                while(temp > 0){
                    n += (temp % 10) * (temp % 10);
                    temp /= 10;
                }
            }else{
                return false;
            }
        }
        return true;
    }
};

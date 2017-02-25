class Solution {
public:
    bool canWinNim(int n) {
        n = (n - 1) % 4 + 1;
        if(n == 4) return false;
        return true;
    }
};

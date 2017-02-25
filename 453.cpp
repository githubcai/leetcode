class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ret = 0, mn = INT_MAX;
        for(int num : nums) mn = min(mn, num);
        for(int num : nums) ret += num - mn;
        return ret;
    }
};

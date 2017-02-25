class Solution {
    int dfs(int n, bool flag){
        if(n <= 2){
            return flag ? n : 1;
        }else{
            return 2 * dfs(n / 2, !flag) - (flag ? 0 : (n % 2 == 0 ? 1 : 0));
        }
    }
public:
    int lastRemaining(int n) {
        return dfs(n, true);
    }
};

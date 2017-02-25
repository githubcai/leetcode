class Solution {
    unordered_map<int, bool> ref;
    
    bool dfs(int maxChoosableInteger, int mask, int desiredTotal, bool role){
        for(int i = 1; i <= maxChoosableInteger; ++i){
            if((mask & (1 << (i - 1))) == 0){
                if(desiredTotal - i <= 0) return role;
                int temp = (mask | (1 << (i - 1)));
                bool flag;
                if(ref.find(temp) != ref.end()){
                    flag = ref[temp];
                }else{
                    flag = dfs(maxChoosableInteger, temp, desiredTotal - i, !role);
                    ref[temp] = flag;
                }
                if(flag == role) return role;
            }
        }
        return !role;
    }
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int temp = maxChoosableInteger * (maxChoosableInteger + 1) / 2;
        if(temp < desiredTotal) return false;
        ref.clear();
        return dfs(maxChoosableInteger, 0, desiredTotal, true);
    }
};

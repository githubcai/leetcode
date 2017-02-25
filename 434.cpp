class Solution {
public:
    int countSegments(string s) {
        int ret = 0, ind = 0, size = s.size();
        while(ind < size){
            if(s[ind] == ' '){
                while(ind < size && s[ind] == ' ') ind += 1;
            }else{
                ret += 1;
                while(ind < size && s[ind] != ' ') ind += 1;
            }
        }
        return ret;
    }
};

class Solution {
    bool isPalindrome(const string &s){
        int left = 0, right = s.size() - 1;
        while(left < right){
            if(s[left] != s[right]) return false;
            left += 1;
            right -= 1;
        }
        return true;
    }
    
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ret;
        int size = s.size();
        if(isPalindrome(s)){
            vector<string> temp;
            temp.push_back(s);
            ret.push_back(temp);
        }
        for(int i = 1; i < size; ++i){
            string pStr = s.substr(0, i);
            if(isPalindrome(pStr)){
                string str = s.substr(i, size - i);
                vector<vector<string>> tRet = partition(str);
                for(int j = 0; j < tRet.size(); ++j){
                    vector<string> temp;
                    temp.push_back(pStr);
                    for(int k = 0; k < tRet[j].size(); ++k) temp.push_back(tRet[j][k]);
                    ret.push_back(temp);
                }
            }
        }
        return ret;
    }
};

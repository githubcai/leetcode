class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> ref({'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'});
        int left = 0, right = s.size() - 1;
        while(left < right){
            auto iter = ref.find(s[left]);
            if(iter == ref.end()){
                left += 1;
                continue;
            }
            iter = ref.find(s[right]);
            if(iter == ref.end()){
                right -= 1;
                continue;
            }
            char c = s[left];
            s[left] = s[right];
            s[right] = c;
            left += 1;
            right -= 1;
        }
        return s;
    }

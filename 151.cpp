class Solution {
public:
    void reverseWords(string &s) {
        int left, right, size = s.size();
        for(left = 0; left < size; ++left){
            if(s[left] != ' ') break;
        }
        for(right = size; right > 0; --right){
            if(s[right - 1] != ' ') break;
        }
        s = s.substr(left, right - left);
        size = 1;
        for(int i = 1; i < s.size(); ++i){
            if(s[i] == ' '){
                s[size++] = ' ';
                while(i < s.size() && s[i] == ' ') i += 1;
            }
            s[size++] = s[i];
        }
        s = s.substr(0, size);
        reverse(s.begin(), s.end());
        size = s.size();
        int first = 0;
        for(int i = 0; i < size; ++i){
            if(s[i] == ' '){
                int second = i - 1;
                while(first < second){
                    char temp = s[first];
                    s[first] = s[second];
                    s[second] = temp;
                    first += 1;
                    second -= 1;
                }
                first = i + 1;
            }
        }
        int second = size - 1;
        while(first < second){
            char temp = s[first];
            s[first] = s[second];
            s[second] = temp;
            first += 1;
            second -= 1;
        }
    }
};

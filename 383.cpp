class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> ran, mag;
        for(char c : ransomNote) ran[c] += 1;
        for(char c : magazine) mag[c] += 1;
        for(auto iter = ran.begin(); iter != ran.end(); ++iter){
            if(iter->second > mag[iter->first]) return false;
        }
        return true;
    }
};

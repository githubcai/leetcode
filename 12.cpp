class Solution {
public:
    string intToRoman(int num) {
        string ge[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        string shi[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string bai[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string qian[] = {"", "M", "MM", "MMM"};
        return qian[num / 1000] + bai[num % 1000 / 100] + shi[num % 100 / 10] + ge[num % 10];
    }
};

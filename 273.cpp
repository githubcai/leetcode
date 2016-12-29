class Solution {
    string below20[20] = {
        "", "One", "Two", "Three", "Four", "Five",
        "Six", "Seven", "Eight", "Nine", "Ten",
        "Eleven", "Twelve", "Thirteen", "Fourteen",
        "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"
    };
    string below100[10] = {
        "", "", "Twenty", "Thirty", "Forty", "Fifty",
        "Sixty", "Seventy", "Eighty", "Ninety"
    };
    
    string getString(int n){
        if(n >= 1000000000){
            return getString(n / 1000000000) + " Billion" + getString(n % 1000000000); 
        }else if(n >= 1000000){
            return getString(n / 1000000) + " Million" + getString(n % 1000000);
        }else if(n >= 1000){
            return getString(n / 1000) + " Thousand" + getString(n % 1000);
        }else if(n >= 100){
            return getString(n / 100) + " Hundred" + getString(n % 100); 
        }else if(n >= 20){
            return " " + below100[n / 10] + getString(n % 10);
        }else if(n > 0){
            return " " + below20[n];
        }
        return "";
    }
public:
    string numberToWords(int num){
        if(num == 0){
            return "Zero";
        }else{
            return getString(num).substr(1);
        }
    }
};

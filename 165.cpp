class Solution {
public:
    int compareVersion(string version1, string version2) {
        while(!version1.empty() && !version2.empty()){
            int temp1 = stoi(version1), temp2 = stoi(version2);
            if(temp1 > temp2){
                return 1;
            }else if(temp1 < temp2){
                return -1;
            }else{
                auto iter = version1.find('.');
                if(iter == string::npos){
                    version1 = "";
                }else{
                    version1 = version1.substr(iter + 1);
                }
                iter = version2.find('.');
                if(iter == string::npos){
                    version2 = "";
                }else{
                    version2 = version2.substr(iter + 1);
                }
            }
        }
        while(!version1.empty()){
            int temp = stoi(version1);
            if(temp != 0) return 1;
            auto iter = version1.find('.');
            if(iter == string::npos){
                version1 = "";
            }else{
                version1 = version1.substr(iter + 1);
            }
        }
        while(!version2.empty()){
            int temp = stoi(version2);
            if(temp != 0) return -1;
            auto iter = version2.find('.');
            if(iter == string::npos){
                version2 = "";
            }else{
                version2 = version2.substr(iter + 1);
            }
        }
        return 0;
    }
};

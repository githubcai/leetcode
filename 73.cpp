class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.size() == 0) return;
        int nRow = matrix.size(), nCol = matrix[0].size();
        bool cFlag = false, rFlag = false;
        for(int i = 0; i < nRow; ++i){
            for(int j = 0; j < nCol; ++j){
                if(matrix[i][j] == 0){
                    matrix[i][0] = matrix[0][j] = 0;
                    if(i == 0) rFlag = true;
                    if(j == 0) cFlag = true;
                }
            }
        }
        for(int i = 1; i < nCol; ++i){
            if(matrix[0][i] == 0){
                for(int j = 1; j < nRow; ++j) matrix[j][i] = 0;
            }
        }
        for(int i = 1; i < nRow; ++i){
            if(matrix[i][0] == 0){
                for(int j = 1; j < nCol; ++j) matrix[i][j] = 0;
            }
        }
        if(rFlag){
            for(int i = 0; i < nCol; ++i) matrix[0][i] = 0;
        }
        if(cFlag){
            for(int i = 0; i < nRow; ++i) matrix[i][0] = 0;
        }
    }
};

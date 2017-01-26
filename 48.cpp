class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if(matrix.size() <= 1) return;
        for(int i = 0; i < matrix.size() / 2; ++i){
            for(int j = 0; j < matrix.size(); ++j){
                swap(matrix[i][j], matrix[matrix.size() - 1 - i][j]);
            }
        }
        for(int i = 0; i < matrix.size(); ++i){
            for(int j = i + 1; j < matrix.size(); ++j){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};

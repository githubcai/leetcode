class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0 || matrix[0][0] > target) return false;
        int left = 0, right = matrix.size() - 1, row;
        while(left <= right){
            int mid = (left + right) / 2;
            if(matrix[mid][0] < target){
                row = mid;
                left = mid + 1;
            }else if(matrix[mid][0] == target){
                return true;
            }else{
                right = mid - 1;
            }
        }
        left = 0, right = matrix[0].size() - 1;
        while(left <= right){
            int mid = (left + right) / 2;
            if(matrix[row][mid] < target){
                left = mid + 1;
            }else if(matrix[row][mid] == target){
                return true;
            }else{
                right = mid - 1;
            }
        }
        return false;
    }
};

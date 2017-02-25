class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        if(matrix.size() == 0 || matrix[0].size() == 0) return ret;
        int rows = matrix.size(), cols = matrix[0].size();
        int size = rows * cols, ind = 0;
        ret.resize(size);
        bool flag = true;
        for(int i = 0; i < rows; ++i){
            vector<int> temp;
            int x = i, y = 0;
            while(x >= 0 && x < rows && y >= 0 && y < cols){
                temp.push_back(matrix[x][y]);
                x -= 1; y += 1;
            }
            if(flag){
                for(auto iter = temp.begin(); iter != temp.end(); ++iter) ret[ind++] = *iter;
            }else{
                for(auto iter = temp.rbegin(); iter != temp.rend(); ++iter) ret[ind++] = *iter;
            }
            flag = !flag;
        }
        for(int i = 1; i < cols; ++i){
            vector<int> temp;
            int x = rows - 1, y = i;
            while(x >= 0 && x < rows && y >= 0 && y < cols){
                temp.push_back(matrix[x][y]);
                x -= 1; y += 1;
            }
            if(flag){
                for(auto iter = temp.begin(); iter != temp.end(); ++iter) ret[ind++] = *iter;
            }else{
                for(auto iter = temp.rbegin(); iter != temp.rend(); ++iter) ret[ind++] = *iter;
            }
            flag = !flag;
        }
        return ret;
    }
};

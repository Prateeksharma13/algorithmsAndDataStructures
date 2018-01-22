class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int number = matrix[0][0];
        for(int j = 1; j < matrix.size(); j++) {
            if(matrix[j].size() > j) {
                if(matrix[j][j] !=number)
                return false;
            } else {
                return true;
            }
        }
        return true;
    }
};

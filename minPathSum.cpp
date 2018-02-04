class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> result(grid.size()+2, vector<int>(grid[0].size()+2, 0));
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(i == 0 && j == 0) {
                    result[0][0] = grid[0][0];
                }
                if(i == 0 && j != 0) {
                    result[i][j] = result[0][j-1] + grid[i][j]; 
                }
                if(i != 0 && j == 0) {
                    result[i][j] = result[i-1][0] + grid[i][j]; 
                }
                if(i != 0 && j != 0) {
                    result[i][j] = min(result[i-1][j], result[i][j-1]) + grid[i][j];
                }
            }
        }
        return result[grid.size()-1][grid[0].size()-1];
    }
};

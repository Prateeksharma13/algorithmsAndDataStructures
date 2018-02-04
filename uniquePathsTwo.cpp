class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> vec(obstacleGrid.size()+2, vector<int>(obstacleGrid[0].size()+2, 1));
        for(int i=0; i<obstacleGrid.size(); i++) {
            for(int j=0; j<obstacleGrid[0].size(); j++) {
                if(i == 0 && j == 0) {
                    vec[i][j] = (!obstacleGrid[0][0]);
                } else if(j == 0 && i != 0) {
                    vec[i][j] = ((!obstacleGrid[i][j])*vec[i-1][j]); 
                } else if(i == 0 && j != 0) {
                    vec[i][j] = ((!obstacleGrid[i][j])*vec[i][j-1]); 
                }
                if(i != 0 && j !=0) {
                    vec[i][j] = ((!obstacleGrid[i][j])*vec[i][j-1]) + ((!obstacleGrid[i][j])*vec[i-1][j]); 
                }
            }
        }
        return vec[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
    }
};

class Solution {
public:
    int row;
    int column;
    int uniquePaths(int m, int n) {
        vector<vector<int> > vec(m+1, vector<int>(n+1, 1));
        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
               vec[i][j] = vec[i][j-1] + vec[i-1][j]; 
            }
        }
        return vec[m-1][n-1];
    }
};
    

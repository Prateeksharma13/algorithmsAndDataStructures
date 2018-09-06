class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> result;
        for(int i = triangle.size()-1; i >=0; i--) {
            for(int j = 0; j < triangle[i].size(); j++) {
                if(i == triangle.size()-1) {
                    result.push_back(triangle[i][j]);
                } else {
                    result[j] = triangle[i][j] + min(result[j], result[j+1]);
                }   
            }
            if(i != triangle.size()-1) {
                result[triangle[i].size()] = INT_MAX;
            }
        }
        int min = INT_MAX;
        for(int i=0; i<result.size(); i++) {
            if(result[i] < min) min = result[i];
        }
        return min;
    }
};

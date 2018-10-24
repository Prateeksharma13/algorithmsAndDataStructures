class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if(costs.size() == 0) return 0;
        for(int i=1; i < costs.size(); i++) {
            for(int j = 0; j < 3; j++) {
                int first = 1;
                int second = 2;
                if(j == 1) first = 0;
                if(j == 2) second = 0;
                costs[i][j] = costs[i][j] + min(costs[i-1][first], costs[i-1][second]);
            }
        }
        return min(min(costs[costs.size()-1][0], costs[costs.size()-1][1]), costs[costs.size()-1][2]);
    }
};

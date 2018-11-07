class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> current;
        vector<vector<int>> result;
        helper(candidates, target, 0, current, result, 0);
        return result;
    }
    
    void helper(vector<int>& candidates, int target, int current, vector<int> currentVector, vector<vector<int>> &result, int begin) {
        if(current == target) {
            result.push_back(currentVector);
            return;
        }
        if(current > target) {
            return;
        }
        
        for(int i=begin; i < candidates.size(); i++) {
            currentVector.push_back(candidates[i]);
            helper(candidates, target, current+candidates[i], currentVector, result, i);
            currentVector.pop_back();
        }
    }
};

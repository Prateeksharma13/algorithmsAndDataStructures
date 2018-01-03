class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        int length_a = findNums.size();
        int length_b = nums.size();
        vector<int> result;
        for(int i = 0; i < length_a; i++) {
            bool currentFound = false;
            bool nextFound = false;
            for(int j = 0; j < length_b; j++) {
                if(findNums[i] == nums[j]) {
                    currentFound = true;
                }
                if(currentFound && findNums[i] < nums[j]) {
                    result.push_back(nums[j]);
                    nextFound = true;
                    j = length_b;
                }
            }
            if(!nextFound) {
                result.push_back(-1);
            }
        }
        return result;
    }
};

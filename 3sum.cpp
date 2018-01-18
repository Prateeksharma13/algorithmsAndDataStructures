#include <map>
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int size = nums.size();
        vector<vector<int>> res;
        for(int i=0; i< size-1; i++) {
            int target = -nums[i];
            int front = i+1;
            int back = size-1;
            
            while(front < back) {
                int total = nums[front] + nums[back];
                if(total < target) {
                    front++;
                } 
                else if(total > target) {
                    back--;
                } else {
                    vector<int> newVector;
                     newVector.push_back(nums[i]);
                     newVector.push_back(nums[front]);
                     newVector.push_back(nums[back]);
                     res.push_back(newVector);
                     while(front < back && nums[front] == newVector[1]) {
                         front++;
                     }
                     while(front < back && nums[back] == newVector[2]) {
                         back--;
                     }
                }
                while(i< size-1 && nums[i] == nums[i+1]) i++;
            }
        }
        return res;
    }
};

#include <map>
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        map<int, bool> mymap;
        for(int i = 0; i < nums.size(); i++) {
              mymap.insert(std::pair<int,bool>(nums[i], true));
        }
        for(int i=1; i<INT_MAX; i++) {
            if(mymap.find(i) == mymap.end()) {
                return i;
            }
        }
    }
};

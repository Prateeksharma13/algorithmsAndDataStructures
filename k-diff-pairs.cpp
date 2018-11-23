class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(nums.size() == 0) return 0;
        sort(nums.begin(), nums.end());
        int n = 0;
        int i = 0;
        if(nums.size()<=1) return 0;
        while(i < nums.size()) {
            int t = i+1;
            while(t < nums.size() &&nums[t] - nums[i] < k) ++t;
            if(t < nums.size() && (nums[t] - nums[i] == k)) ++n;
            int j = i+1;
            while(j < nums.size() && nums[j] == nums[i]) ++j;
            i = j;
        }
        return n;
    }
};

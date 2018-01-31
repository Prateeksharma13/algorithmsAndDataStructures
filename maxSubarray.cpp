class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        int pre = 0;
        for(int i=0; i<nums.size(); i++) {
            int current = nums[i]+pre; //series
            pre = max(current, nums[i]);
            if(pre > res) {
                res = pre;
            }
        }  
        return res;
    }
};

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int size = nums.size();
        if(target < nums[0]) return 0;
        if(target > nums[size-1]) return size;
        for(int i=0; i<size; i++) {
            if(nums[i] == target) return i;
            if(target > nums[i] && target < nums[i+1]) return i+1;
        }
        
    }
};

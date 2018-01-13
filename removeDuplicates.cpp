class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        for(int i=0; i < size; i++) {
            if(nums[i] == val) {
                nums.erase(nums.begin()+i);
                i = i-1;
                size = nums.size();
            }
        } 
        return size;
    }
};

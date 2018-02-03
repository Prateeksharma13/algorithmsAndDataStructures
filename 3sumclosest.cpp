class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int size =  nums.size();
        int closest = INT_MAX;
        int result = 0;
        for(int i=0; i<size-2;i++) {
            for(int j=i+1; j < size-1; j++) {
                int k = j+1;
                while(true) {
                    if(k == size) {
                            break;                            
                    }
                    int sum = nums[i]+nums[j]+nums[k];
                    int difference = abs(target-sum);
                    if(difference < closest) {
                        closest = difference;
                        result = sum;
                    }
                    k = k+1;
                }
            }
        }
        return result;
    }
};

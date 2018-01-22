class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size()-1;
        int maximum = 0;
        while(i!= j) {
            int current = (j-i)*min(height[j], height[i]);
            maximum = max(current, maximum);
            if(height[i] > height[j]) {
                j--;
            } else {
                i++;
            }
        }
        return maximum;
    }
};

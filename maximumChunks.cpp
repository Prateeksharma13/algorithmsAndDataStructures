class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int maximum = 0;
        int count = 0;
        int size = arr.size();
        maximum = arr[0];
        for(int i=0; i<size; i++) {
            maximum = max(maximum, arr[i]);
            if(i == maximum) count++;
        }
        return count;
    }
};

class Solution {
public:
    vector<int> pourWater(vector<int>& heights, int V, int K) {
        int size = heights.size();
        while(V!=0) {
            int minLeft = INT_MAX;
            int minIndexLeft = -1;
            int minRight = INT_MAX;
            int minIndexRight = -1;
            bool inserted = false;
            for(int i=0; i < K; i++) {
                inserted = false;
                if(heights[i] > heights[i+1]) {
                    minLeft = heights[i+1];
                    minIndexLeft = i+1;
                } else if(heights[i] <= minLeft){
                    minLeft = heights[i];
                    minIndexLeft = i;
                }
            }
            if((minLeft < heights[K])) {
                heights[minIndexLeft] +=1;
                V -=1;
                inserted = true;
            } else{
                for(int i = size-1; i > K ; i--){
                    if(heights[i] > heights[i-1]) {
                        minRight = heights[i];
                        minIndexRight = i;
                    } else if(heights[i] <= minRight) {
                       minRight = heights[i];
                       minIndexRight = i; 
                    }
                }
                 if((minRight < heights[K])) {
                    heights[minIndexRight] +=1;
                    V -=1;
                    inserted = true;
                }
            }
            if(((minRight == heights[K]) && (heights[K]== minLeft)) || (!inserted)) {
                heights[K] += 1;
                V -= 1;
            }
        }
        return heights;
    }
};

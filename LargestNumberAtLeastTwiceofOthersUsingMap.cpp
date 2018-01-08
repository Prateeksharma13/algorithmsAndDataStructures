class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        std::map<int,int> mymap;
        for(int i =0; i<nums.size(); i++){
            mymap.insert ( std::pair<int,int>(nums[i], i));
        }
        std::map<int,int>::iterator it=mymap.end();
        --it;
        int last = it->first;
        int index = it->second;
        --it;
        int lastButOne = it->first;
        if(lastButOne == last) return 0;
        if(2*lastButOne <= last) return index;
        return -1;
    }
};

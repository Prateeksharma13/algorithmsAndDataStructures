class Solution {
public:
    int romanToInt(string s) {
        if(!s.length()) return 0;
        unordered_map <char, int> dict = {
            {'I', 1},
            {'V', 5},
            {'X', 10}, 
            {'L', 50},
            {'C', 100},
            {'D', 500}, 
            {'M', 1000}
        };
        
        int sum = 0;
        
        unordered_map <char, int>::iterator pointer = dict.find(s[s.length()-1]);
        sum = pointer->second;
        int next = sum;
        
        for(int i = s.length()-2; i >=0; i--) {
            pointer = dict.find(s[i]);
            if(pointer->second < next) {
                sum = sum - pointer->second;
            } else {
                sum = sum + pointer->second;
            }
            next = pointer->second;
        }
        return sum;

    }
};

class Solution {
public:
    string longest = "";
    string longestCommonPrefix(vector<string>& strs) {
        int size = strs.size();
        if(size) {
            int firstSize = strs[0].length();
            for(int i = 0; i < firstSize; i++) {
                for(int j=1; j<size; j++) {
                    if(!(strs[0][i] == strs[j][i])) return longest;
                }
                longest += strs[0][i];
            }
        }
        return longest;
    }
};

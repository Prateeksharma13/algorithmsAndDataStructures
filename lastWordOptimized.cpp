class Solution {
public:
    int lengthOfLastWord(string s) {
        int l = s.length()-1;
        int c = 0;
        while(l >= 0 && s[l] == ' ') l--;
        while(l>=0) {
            if(s[l] != ' ') {
                c++;
                l--;
            } else {
                return c;
            }
        }
        return c;
    }
};

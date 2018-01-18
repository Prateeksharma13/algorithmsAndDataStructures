class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = s.length();
        int count = 0;
        bool found = false;
        for(int i=length-1; i>=0; i--) {
            if(!found && s[i] != ' ') {
                found = true;
            }
            if(found == true && s[i] != ' ') count++;
            if(found == true && s[i] == ' ') return count;
        }
        return count;
    }
};

class Solution {
public:
    int titleToNumber(string s) {
        int count = 1;
        int result = 0;
        for(int i=s.length()-1; i >=0; i--) {
            result += (s[i] - 'A' + 1)*(count);
            count*= 26;
        }
        return result;
    }
};

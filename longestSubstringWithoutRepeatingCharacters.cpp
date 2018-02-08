class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> a(256, -1);
        int size = s.length();
        int pointer = 0;
        int res = 0;
        for(int i=0; i<size; i++) {
            if(a[int(s[i])] != -1) {
                if(i-pointer > res) res = i-pointer;
                pointer = max(a[int(s[i])] + 1, pointer); 
                a[int(s[i])] = i;
            } else {
                if(i-pointer+1 > res) res = i-pointer+1;
                a[int(s[i])] = i;
            }
        }
        if(size-pointer > res) res = size-pointer;
        return res;
    }
};

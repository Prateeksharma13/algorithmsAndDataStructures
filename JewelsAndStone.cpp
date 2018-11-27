class Solution {
public:
    int numJewelsInStones(string J, string S) {
        map<char, int> lookup;
        for(int i=0; i < S.length(); i++) {
            if(lookup.find(S[i]) == lookup.end()) {
                lookup.insert(pair<char, int>(S[i], 1));
            } else {
                lookup[S[i]] += 1;
            }
        }
        int res = 0;
        
        for(int j =0; j < J.length(); j++) {
            if(lookup.find(J[j]) != lookup.end()) {
                res += lookup[J[j]];
            }
        }
        return res;
    }
};

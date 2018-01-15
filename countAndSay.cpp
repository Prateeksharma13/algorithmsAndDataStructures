class Solution {
public:
    string countAndSay(int n) {
        string initial = "1";
        string final;
        for(int i = 1; i < n; i++) {
            int size = initial.length();
            for(int j = 0; j < size; j++) {
                int count = 1;
                while((j < size-1) && initial[j] == initial[j+1]) {
                    count++;
                    j++;
                }
                final += std::to_string(count)+ initial[j];
                if(j == size -1) {
                    initial = final;
                    final = "";
                }
            }
        }
        return initial;
    }
};

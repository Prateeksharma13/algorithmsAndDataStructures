class Solution {
public:
        int myAtoi(string str) {
            int len = str.length();
            for(int i =0; i < len; i++) {
                if(str[i] == ' ') {
                    continue;
                } else {
                     str = str.substr (i,len);
                    break;
                }
            }
            bool isNegative = false;
            if(str[0] == '-'){
                isNegative = true;
                str.erase(0,1);
            } else if(str[0] == '+') {
                str.erase(0,1);
            }
            len = str.length();
            string result = "";
            for(int i =0; i < len; i++) {
                if(isdigit(str[i])) {
                    result += str[i];
                } else {
                    break;
                }
            }
            double intres = 0;
            for(int i =0; i < result.length(); i++) {
                if(isdigit(result[i])) {
                    intres += (int(result[i])-48)*(pow(10,result.length()-i-1));
                    if(intres > INT_MAX) {
                        if(isNegative) {
                            return -2147483648;
                        }
                        return 2147483647;
                    }
                } else {
                    break;
                }
            }
            if(isNegative) {
                intres*=-1;
            }
            return intres;
    }
};

#include <math.h>
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        int tens = -1;
        int number = x;
        while(number != 0){
            number = number/10;
            tens = tens+1;
        }
        number = 0;
        int new_tens = tens;
        while(tens != new_tens/2 && tens != -1) {
            if((x/int(pow(10, tens)))%(10) == x/(int(pow(10, new_tens-tens)))%10) {
                tens = tens-1;
                continue;
            } else {
                return false;
            }
        }
        return true;
    }
};

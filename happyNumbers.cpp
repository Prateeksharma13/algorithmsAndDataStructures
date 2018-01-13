#include <cmath>
#include <unordered_map>
class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, bool> visits;
        int newn = 0;
        int count = 1;
        while(n != 1){
            while(n != 0) {
                int number = (n%int(pow(10, 1)));
                newn += number * number;
                n = n/10;
            }
            n = newn;
            if(visits.find(newn) !=  visits.end()) return false;
            std::pair<int, bool> numberInsert (newn, true);
            visits.insert(numberInsert);
            newn = 0;
        }
        return true;
    }
};

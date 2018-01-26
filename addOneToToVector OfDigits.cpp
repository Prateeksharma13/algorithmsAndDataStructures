class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        int carry = 1;
        for(int i=size-1; i >=0 ; i--) {
            int temp = digits[i]+carry;
            if(temp > 9) {
                digits[i] = temp%10;
                carry = 1;
            } else {
                digits[i] = temp;
                carry = 0;
            }
        }
        if(carry) {
            digits.insert(digits.begin(), carry);
        }
        return digits;
    }
};

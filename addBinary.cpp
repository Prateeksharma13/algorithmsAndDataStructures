class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.length()-1;
        int j = b.length()-1;
        int carry = 0;
        string res = "";
        while(i >= 0 || j >= 0) {
            int sum = 0;
            if(i >= 0) {
                if(a[i] == '1') {
                    sum += 1;
                }
                i--;
            }
            if(j >= 0) {
                if(b[j] == '1') {
                    sum += 1;
                }
                j--;
            }
            if(sum+carry == 3) {
                carry = 1;
                res = "1"+res;
            } 
            else if(sum+carry == 2) {
                carry = 1;
                res = "0"+res; 
            }
            else if(sum+carry == 1) {
                carry = 0;
                res = "1"+res;  
            }
            else{
                carry = 0;
                res = "0"+res;  
            }
        }
        if(carry) res = "1"+res;
        return res;
    }
};

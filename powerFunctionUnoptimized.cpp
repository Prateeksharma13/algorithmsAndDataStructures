class Solution {
public:
    double myPow(double x, int n) {
        if(x == 1) return x;
        if(x == -1 && n%2==0) return -x;
        if(x == -1 && n%2!=0) return x;
        double pow = x;
        if(n > 0) {
            while(n > 1) {
                if(x == 0) return x;
                x = x*pow;
                n -= 1;
            }     
        } else {
            while(n < 1) {
                if(x == 0) return x;
                x = x/pow;
                n += 1;
            }    
        }       
        return x;
    }
};

class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.0;
        long long p = abs(n);
        while(p){
            if(p & 1) res *= x;
            x *= x;
            p = p/2;
        }
       if(n<0) return 1/res;
       return res;
    }
};

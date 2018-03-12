/*
50. Pow(x, n)

Implement pow(x, n).


Example 1:

Input: 2.00000, 10
Output: 1024.00000
Example 2:

Input: 2.10000, 3
Output: 9.26100
*/
class Solution {
public:
    double myPow(double x, int n) {
        double a=1;
        bool f=false;
        if(n<0){
            x=1/x;
            n=n*-1;
        }else if(n==0){
            return 1.0;
        }
        if(x<0){
            x=abs(x);
            f=true;
        }
        if(x==1.0 || x==0.0){
            if(f && n%2!=0){
                return -1*x;
            }
            return x;
        }
        if(x>1 && n==INT_MAX){
            return INFINITY;
        }
        if(x>0 && x<1 && (n==INT_MAX || n==INT_MIN)){
            return 0.0;
        }
        for(int i=0;i<n;i++){
            a=a*x;
        } 
        if(f && n%2!=0){
            return -a;
        }
        return a;
    }
};
class Solution {
public:
    int reverse(int x) {
        int n = abs(x);
        long r=0;
        while(n>0){
            int b=n%10;
            r=(r*10)+b;
            n=n/10;
        }
        if(r>INT_MAX){
            return 0;
        }
        if(x<0){
            return -(int)r; 
        }
        return (int)r;
    }
};
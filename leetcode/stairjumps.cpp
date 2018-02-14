class Solution {
public:
    int m=1000000007;
    int findCount(int n){
        int c=0;
        if(n<0){
            return 0;
        }
        if(n==0){
            return 1;
        }
        c=c%m+findCount(n-1)%m+findCount(n-2)%m;
        return c%m;
    }
    int climbStairs(int n) {
        int c=findCount(n);
        return c%m;
    }
};
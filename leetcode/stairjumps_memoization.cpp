class Solution {
public:
    int findCount(int n,int memo[]){
        int c=0;
        if(n<0){
            return 0;
        }
        if(n==0){
            return 1;
        }
        if(memo[n]>0){
            return memo[n];
        }
        memo[n]=memo[n]+findCount(n-1,memo)+findCount(n-2,memo);
        return memo[n];
        // c=c+findCount(n-1,memo)%m+findCount(n-2,memo);
        // return c;
    }
    int climbStairs(int n) {
        int memo[n+1];
        for(int i=0;i<n+1;i++){
            memo[i]=0;
        }
        int c=findCount(n,memo);
        return c;
    }
};
/*
279. Perfect Squares

Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.
*/
class Solution {
public:
    int numSquares(int n) {
        int s = sqrt(n);
        int a[s+1][n+1];
        for(int i=1;i<=s;i++){
            for(int j=1;j<=n;j++){
                if(i==1){
                    a[i][j]=j;
                }else{
                    if(j<(i*i)){
                        a[i][j]=a[i-1][j];
                    }else{
                        int c = j-(i*i);
                        if(c==0){
                            a[i][j]=1;
                            continue;
                        }
                        int k = 1+min(a[i][c],a[i-1][c]);
                        a[i][j]=min(a[i-1][j],k);
                    }
                }
            }
        }
        return a[s][n];
    }
};
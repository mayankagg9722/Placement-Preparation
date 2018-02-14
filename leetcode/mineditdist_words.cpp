class Solution {
public:
    int findCount(string word1, string word2,int m,int n){
        int dp[m+1][n+1];
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0){
                    dp[i][j]=j;
                    continue;
                }
                if(j==0){
                    dp[i][j]=i;
                    continue;
                }
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }else{
                    dp[i][j]=1+min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
                }
            }
        }
        return dp[m][n];
    }
    int minDistance(string word1, string word2) {
        if(word1==word2){
            return 0;
        }
        int k=findCount(word1,word2,word1.length(),word2.length());
        return k;
    }
};
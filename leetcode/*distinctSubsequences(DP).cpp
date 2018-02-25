/*
115. Distinct Subsequences

Given a string S and a string T, count the number of distinct subsequences of S which equals T.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.

*/
class Solution {
public:
    // int sum=0;
    // void findUtil(string s,string t,int searchindex,int nextindex){
    //     if(nextindex>=t.length()){
    //         sum+=1;
    //     }
    //     for(int i=searchindex;i<s.length();i++){
    //         if(s[i]==t[nextindex]){
    //             findUtil(s,t,i+1,nextindex+1);
    //         }
    //     }
    // }
    int numDistinct(string s, string t) {
        // findUtil(s,t,0,0);
        int xs=t.length()+1,ys=s.length()+1;
        int dp[xs][ys];
        for(int i=0;i<xs;i++){
            dp[i][0]=0;
        }
        for(int i=0;i<ys;i++){
            dp[0][i]=1;
        }
        for(int i=1;i<xs;i++){
            for(int j=1;j<ys;j++){
                if(t[i-1]==s[j-1]){
                    dp[i][j]=dp[i][j-1]+dp[i-1][j-1];
                }else{
                    dp[i][j]=dp[i][j-1];
                }
            }
        }
        return dp[xs-1][ys-1];
    }
};
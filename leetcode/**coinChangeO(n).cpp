/*
322. Coin Change
You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:
coins = [1, 2, 5], amount = 11
return 3 (11 = 5 + 5 + 1)

Example 2:
coins = [2], amount = 3
return -1.


*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(coins.size()==0){
            return -1;
        }
        if(amount<1){
            return 0;
        }
        int dp[amount+1];
        for(int i=1;i<=amount;i++){
            dp[i]=INT_MAX;
        }
        for(int j=1;j<=amount;j++){
            for(int i=0;i<coins.size();i++){
                if(coins[i]==j){
                    dp[j]=1;
                    continue;
                }
                if(coins[i]<j){
                    int k = dp[j-coins[i]];
                    if(k!=INT_MAX){
                        dp[j]=min(k+1,dp[j]);
                    }
                }
            }
        }
        if(dp[amount]==INT_MAX){
            return -1;
        }
        return dp[amount];
    }
};
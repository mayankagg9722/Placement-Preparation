/*
121. Best Time to Buy and Sell Stock

Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Example 1:
Input: [7, 1, 5, 3, 6, 4]
Output: 5

max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)
Example 2:
Input: [7, 6, 4, 3, 1]
Output: 0

In this case, no transaction is done, i.e. max profit = 0.
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int s = prices.size();
        if(s==0){
            return 0;
        }
        int minA[s];
        int maxA[s];
        int foundMIN=INT_MAX;
        int foundMAX=INT_MIN;
        for(int i=0;i<s;i++){
            if(foundMIN>prices[i]){
                foundMIN=prices[i];
            }
            minA[i]=foundMIN;
        }
        for(int i=s-1;i>=0;i--){
            if(foundMAX<prices[i]){
                foundMAX=prices[i];
            }
            maxA[i]=foundMAX;
        }
        int k=INT_MIN;
        for(int i=0;i<s;i++){
            k=max(k,(maxA[i]-minA[i]));
        }
        if(k<0){
            return 0;
        }
        return k;
    }
};
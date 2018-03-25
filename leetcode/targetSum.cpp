/*
494. Target Sum

You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.

Example 1:
Input: nums is [1, 1, 1, 1, 1], S is 3. 
Output: 5
Explanation: 

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.
Note:
The length of the given array is positive and will not exceed 20.
The sum of elements in the given array will not exceed 1000.
Your output answer is guaranteed to be fitted in a 32-bit integer.

class Solution {
public:
    int k=0;
    void util(vector<int> n,int i,int t,int s){
        if(i==n.size()){
            if(s==t){
                k++;    
            }
            return;
        }
        util(n,i+1,t,s+n[i]);
        util(n,i+1,t,s-n[i]);
    }
    int findTargetSumWays(vector<int>& n, int t) {
        util(n,0,t,0);
        return k;
    }
};
*/

class Solution {
public:
    int k=0;
    int memo[21][2001];
    int util(vector<int> n,int i,int t,int s){
        if(i==n.size()){
            if(s==t){
                k++;
                return 1;
            }
            return 0;
        }
        if(memo[i][s+1000]!=INT_MIN){
            return memo[i][s+1000];
        }
        int add = util(n,i+1,t,s+n[i]);
        int sub = util(n,i+1,t,s-n[i]);
        memo[i][s+1000]=add+sub;
        return memo[i][s+1000];
    }
    int findTargetSumWays(vector<int>& n, int t) {
        for(int i=0;i<21;i++){
            for(int j=0;j<2001;j++){
                memo[i][j]=INT_MIN;
            }
        }
        return util(n,0,t,0);
    }
};
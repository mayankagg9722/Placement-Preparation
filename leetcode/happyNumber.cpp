/*
202. Happy Number

Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 19 is a happy number

12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
*/
class Solution {
public:
    int sumNo(int n){
        int a=0;
        while(n>0){
            int b=n%10;
            a+=(b*b);
            n=n/10;
        }
        return a;
    }
    bool isHappy(int n) {
        if(n==1){
            return true;
        }
        int t=n;
        vector<int> a;
        a.push_back(n);
        while(1){
            int k = t;
            if(k==1){
                return true;
            }
            t = sumNo(t);
            if(find(a.begin(),a.begin()+a.size(),t)!=a.end()){
                return false;
            }
            a.push_back(t);
        }
        return false;
    }
};
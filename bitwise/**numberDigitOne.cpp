/*
233. Number of Digit One

Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.

For example:
Given n = 13,
Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.


*/
class Solution {
public:
    int lengthDigit(int n){
        int c=0;
        while(n>0){
            c++;
            n=n/10;
        }
        return c;
    }
    int countDigitOne(int n) {
        if(n<=0){
            return 0;
        }else if(n<10){
            return 1;
        }
        int length=lengthDigit(n);
        int base=pow(10,length-1);
        int answer=n/base;
        int remainder=n%base;
        int m;
        if(answer==1){
            m=n-base+1;
        }else{
            m=base;
        }
        return countDigitOne(base-1)*answer+m+countDigitOne(remainder);
    }
};
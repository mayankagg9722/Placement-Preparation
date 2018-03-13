/*

263. Ugly Number

Write a program to check whether a given number is an ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.

Note that 1 is typically treated as an ugly number.
*/
class Solution {
public:
    bool isPrime(int t){
        for(int i=2;i<=t/2;i++){
            if(t%i==0){
                return false;
            }
        }
        return true;
    }
    bool isUgly(int num) {
        if(num<0){
            return false;
        }
        if(num==1){
            return true;
        }
        if(num==0 || num==INT_MAX){
            return false;
        }
        while(num%2==0){
            num=num/2;
        }
        while(num%3==0){
            num=num/3;
        }
        while(num%5==0){
            num=num/5;
        }
        if(num==1){
            return true;
        }
        return false;
    }
};
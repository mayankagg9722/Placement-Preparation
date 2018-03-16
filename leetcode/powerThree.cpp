/*
326. Power of Three
DescriptionHintsSubmissionsDiscussSolution
Given an integer, write a function to determine if it is a power of three.
*/
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==1){
            return true;
        }
        while(n>=3){
            double k = n/3.0;
            int a = k;
            if((k-a)!=0){
                return false;
            }
            n=n/3;
            if(n==3 || n==1){
                return true;
            }
        }
        return false;
    }
};
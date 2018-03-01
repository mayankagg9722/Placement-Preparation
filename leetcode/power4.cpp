 /*
342. Power of Four

Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

Example:
Given num = 16, return true. Given num = 5, return false.

Follow up: Could you solve it without loops/recursion?

Credits:
Special thanks to @yukuairoy for adding this problem and creating all test cases.
 */
 class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==0 || n==INT_MIN){
            return false;
        }
        int k = n & (n-1);
        int k1 = (int)log2(n);
        if( k==0 && k1%2==0 ){
            return true;
        }
        return false;
    }
};
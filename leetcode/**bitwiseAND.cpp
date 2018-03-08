/*

201. Bitwise AND of Numbers Range

Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

For example, given the range [5, 7], you should return 4.

Credits:
Special thanks to @amrsaqr for adding this problem and creating all test cases.

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int k = m;
        m = m + 1;
        while(m<=n){
            if(k==0){
                break;
            }
            k = k & m;
            if(m==INT_MAX){
                break;
            }
            m = m + 1;
        }
        return k;
    }
};
*/

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if(m==0){
            return 0;
        }
        int count=0;
        while(m!=n){
            m=m>>1;
            n=n>>1;
            count++;
        }
        return m<<count;
    }
};

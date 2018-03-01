/*
191. Number of 1 Bits

Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).

For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.
*/
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int c=0;
        while(n){
            n = n & (n-1);
            c++;
        }
        return c;
    }
};
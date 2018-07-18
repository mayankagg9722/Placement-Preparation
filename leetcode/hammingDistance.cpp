/*
461. Hamming Distance

The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, calculate the Hamming distance.

Note:
0 ≤ x, y < 231.

Example:

Input: x = 1, y = 4

Output: 2

Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑

The above arrows point to positions where the corresponding bits are different.
*/
class Solution {
public:
    int hammingDistance(int x, int y) {
        int c=0;
        while(x & y){
            cout<<"w1\n";
            int p = x & 1;
            int q = y & 1;
            if((p==1 && q==0) || (p==0 && q==1)){
                c++;
            }
            x = x >> 1;
            y = y >> 1;
        }
        while(x){
            if(x&1){
                c++;
            }
            x = x >> 1;
        }
        while(y){
            if(y&1){
                c++;
            }
            y = y >> 1;
        }
        return c;
    }
};
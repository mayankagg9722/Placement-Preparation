/*
338. Counting Bits

Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Example:
For num = 5 you should return [0,1,1,2,1,2].
*/
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> a;
        for(int i=0;i<=num;i++){
            int c=0;
            int k=i;
            while(k){
                if(k & 1){
                    c++;
                }
                k = k >> 1;
            }
            a.push_back(c);
        }
        return a;
    }
};
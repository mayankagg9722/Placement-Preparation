/*
264. Ugly Number II
Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note that 1 is typically treated as an ugly number, and n does not exceed 1690.
*/
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> a;
        a.push_back(1);
        int i2=0,i3=0,i5=0;
        int k;
        while(a.size()<n){
            k = min(a[i2]*2,min(a[i3]*3,a[i5]*5));
            if(k==a[i2]*2){
                i2++;
            }
            if(k==a[i3]*3){
                i3++;
            }
            if(k==a[i5]*5){
                i5++;
            }
            a.push_back(k);
        }
        return a[n-1];
    }
};
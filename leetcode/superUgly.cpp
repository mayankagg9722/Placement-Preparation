/*
313. Super Ugly Number

Write a program to find the nth super ugly number.

Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k. For example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32] is the sequence of the first 12 super ugly numbers given primes = [2, 7, 13, 19] of size 4.

Note:
(1) 1 is a super ugly number for any given primes.
(2) The given numbers in primes are in ascending order.
(3) 0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.
(4) The nth super ugly number is guaranteed to fit in a 32-bit signed integer.
*/
class Solution {
public:
    int nthSuperUglyNumber(int t, vector<int>& primes) {
        vector<int> ar;
        ar.push_back(1);
        vector<int> index (primes.size(),0);
        while(ar.size()!=t){
            int m=INT_MAX;
            int pos;
            for(int p=0;p<primes.size();p++){
                if(m>primes[p]*ar[index[p]]){
                    m=primes[p]*ar[index[p]];
                    pos=p;
                }
            }
            index[pos]++;
            if(ar[ar.size()-1]!=m){
                ar.push_back(m);    
            }
        }
        return ar[t-1];
    }
};
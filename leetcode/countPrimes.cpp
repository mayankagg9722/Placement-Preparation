/*
204. Count Primes

Description:

Count the number of prime numbers less than a non-negative number, n.
*/
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> a;
        for(int i=0;i<=n;i++){
            a.push_back(false);
        }
        int k=1;
        for(int i=2;i<=n;i++){
            int t=2;
            while((i*t)<=n){
                a[(i*t)]=true;
                t++;
            }
        }
        int count=0;
        for(int i=2;i<n;i++){
            if(a[i]==false){
                count+=1;
            }
        }
        return count;
    }
};
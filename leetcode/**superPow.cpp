/*
372. Super Pow
Your task is to calculate ab mod 1337 where a is a positive integer and b is an extremely large positive integer given in the form of an array.

Example1:

a = 2
b = [3]

Result: 8
Example2:

a = 2
b = [1,0]

Result: 1024

TLE

class Solution {
public:
    int mod=1337;
    int findPow(int n,int k){
        int m=1;
        for(int i=1;i<=k;i++){
            m=m*n;
            if(m==mod){
                return 0;
            }
            if(m>mod){
                m=m%mod;
            }
        }
        return m;
    }
    int superPow(int a, vector<int>& b) {
        int s = b.size();
        int k=0;
        int p=1;
        a=a%mod;
        for(int i=s-1;i>=0;i--){
            int val = b[i]*pow(10,k++);
            p = p*findPow(a,val);
            if(p>mod){
                p=p%mod;
            }
        }
        return p;
    }
};
*/

class Solution {
public:
    int mod=1337;
    int findPow(int n,int k){
        n=n%mod;
        int m=1;
        for(int i=1;i<=k;i++){
            m=m*n;
            if(m==mod){
                return 0;
            }
            if(m>mod){
                m=m%mod;
            }
        }
        return m;
    }
    int superPow(int a, vector<int>& b) {
        if(b.empty()){
            return 1;
        }
        int last = b.back();
        b.pop_back();
        return (findPow(superPow(a,b),10)*findPow(a,last))%mod;
    }
};
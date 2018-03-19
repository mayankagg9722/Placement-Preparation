/*
396. Rotate Function
Given an array of integers A and let n to be its length.

Assume Bk to be an array obtained by rotating the array A k positions clock-wise, we define a "rotation function" F on A as follow:

F(k) = 0 * Bk[0] + 1 * Bk[1] + ... + (n-1) * Bk[n-1].

Calculate the maximum value of F(0), F(1), ..., F(n-1).

Note:
n is guaranteed to be less than 105.

Example:

A = [4, 3, 2, 6]

F(0) = (0 * 4) + (1 * 3) + (2 * 2) + (3 * 6) = 0 + 3 + 4 + 18 = 25
F(1) = (0 * 6) + (1 * 4) + (2 * 3) + (3 * 2) = 0 + 4 + 6 + 6 = 16
F(2) = (0 * 2) + (1 * 6) + (2 * 4) + (3 * 3) = 0 + 6 + 8 + 9 = 23
F(3) = (0 * 3) + (1 * 2) + (2 * 6) + (3 * 4) = 0 + 2 + 12 + 12 = 26

So the maximum value of F(0), F(1), F(2), F(3) is F(3) = 26.

##TLE


class Solution {
public:
    void reverse(vector<int> &a,int s,int e){
        int i=s;
        int j=e-1;
        while(i<j){
            int t = a[i];
            a[i]=a[j];
            a[j]=t;
            i++;
            j--;
        }
    }
    vector<int> rotate(vector<int> a , int k){
        vector<int> n = a;
        reverse(n,0,n.size());
        reverse(n,0,k);
        reverse(n,k,n.size());
        return n;
    }
    int maxRotateFunction(vector<int>& A) {
        int n=A.size();
        if(n<2){
            return 0;
        }
        int ans=INT_MIN;
        for(int i=0;i<=n-1;i++){
            vector<int> n = rotate(A,i);
            int s=0;
            for(int j=0;j<n.size();j++){
                if(n[j]==INT_MAX){
                    return INT_MAX;
                }
                if(n[j]==INT_MIN){
                    return INT_MIN;
                }
                s+=(n[j]*j);
            }
            if(ans<s){
                ans=s;
            }
        }
        return ans;
    }
};
*/

class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int len=A.size();
        if(len==0){
            return 0;
        }
        int F=0;
        int sum=0;
        for(int i=0;i<len;i++){
            F+=i*A[i];
            sum+=A[i];
        }
        int m = F;
        for(int i=len-1;i>=0;i--){
            F=F+sum-len*A[i];
            m=max(m,F);
        }
        return m;
    }
};





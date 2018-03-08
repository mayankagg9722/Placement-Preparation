/*
718. Maximum Length of Repeated Subarray

Given two integer arrays A and B, return the maximum length of an subarray that appears in both arrays.

Example 1:
Input:
A: [1,2,3,2,1]
B: [3,2,1,4,7]
Output: 3
Explanation: 
The repeated subarray with maximum length is [3, 2, 1].
*/
class Solution {
public:
    int m = INT_MIN;
    int count(vector<int> A, vector<int> B,int i,int j,int s){
        while(i<A.size() && j<B.size() && A[i]==B[j]){
            s++;
            i++;
            j++;
        }
        return s;
    }
    int doFind(vector<int> A, vector<int> B,int i,int ele){
        int nm = INT_MIN;
        int myCount,p,x,z;
        for(int k=0;k<B.size();k++){
            if(B[k]==ele){
                p=0;
                x=i-1;
                z=k-1;
                while(x>=0 && z>=0 && A[x]==B[z]){
                    p++;
                    x--;
                    z--;
                }
                myCount=count(A,B,i+1,k+1,1);
                m=max(m,p+myCount);
                nm=max(nm,myCount);
            }
        }
        return nm==INT_MIN ? 1 : nm;
    }
    int findLength(vector<int>& A, vector<int>& B) {
        int sa=A.size();
        int sb=B.size();
        vector<int> :: iterator it;
        if(sa==0 || sb==0){
            return 0;
        }
        int i=0;
        while(i<sa){
            int ele = A[i];
            int t=doFind(A,B,i,ele);
            i+=t;
        }
        return m==INT_MIN ? 0 : m;
    }
};
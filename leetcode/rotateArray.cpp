/*
189. Rotate Array

Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
*/
class Solution {
public:
    void reverse(vector<int>& n,int s,int e){
        while(s<e){
            int t=n[s];
            n[s]=n[e];
            n[e]=t;
            s++;
            e--;
        }
    }
    void rotate(vector<int>& n, int k) {
        k=k%(n.size());
        if(k>0){
            reverse(n,0,n.size()-1);
            reverse(n,0,k-1);
            reverse(n,k,n.size()-1);
        }
    }        
};
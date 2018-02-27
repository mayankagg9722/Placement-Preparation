/*
153. Find Minimum in Rotated Sorted Array

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.
*/
class Solution {
public:
    int m=INT_MAX;
    void findUtil(vector<int> &n,int s,int e){
        if(s>e){
            return;
        }
        if(n[s]<=n[e]){
            m=min(m,n[s]);
        }else{
            int middle = (s+e)/2;
            findUtil(n,0,middle);
            findUtil(n,middle+1,e);
        }
    }
    int findMin(vector<int>& n) {
        if(n.size()==0){
            return 0;
        }
        int s = n.size()-1;
        findUtil(n,0,s);
        return m;
    }
};
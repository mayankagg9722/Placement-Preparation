/*
154. Find Minimum in Rotated Sorted Array II

Follow up for "Find Minimum in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

The array may contain duplicates.


*/
class Solution {
public:
    int m=INT_MAX;
    void findUtil(vector<int> &n,int s,int e){
        if(s>e){
            return;
        }
        if(s==e){
            m=min(m,n[s]);
            return;
        }
        int middle =(s+e)/2;
        if(n[middle]<n[e]){
            findUtil(n,s,middle);
        }else if(n[middle]>n[e]){
            findUtil(n,middle+1,e);
        }else{
            findUtil(n,s,middle);
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
/*
162. Find Peak Element

A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
*/
class Solution {
public:
    int findPeakElement(vector<int>& n) {
        int i=0;
        int res=0;
        int j=n.size()-1;
        while(i<=j){
            if(i==0 && n[i]>n[i+1] && n[i]>INT_MIN){
                res=0;
                break;
            }
            if(j==n.size()-1 && n[j]>n[j-1] && n[j]>INT_MIN){
                res=j;
                break;
            }
            if(n[i]>n[i+1] && n[i]>n[i-1]){
                res=i;
                break;
            }
            if(n[j]>n[j+1] && n[j]>n[j-1]){
                res=j;
                break;
            }
            i++;
            j--;
        }
        return res;
    }
};
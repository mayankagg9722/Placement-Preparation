/*
88. Merge Sorted Array
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
 The number of elements initialized in nums1 and nums2 are m and n respectively.
*/
class Solution {
public:
    void merge(vector<int>& n1, int m, vector<int>& n2, int n) {
        int k = m+n-1;
        int i=m-1;
        int j=n-1;
        while(i>=0 && j>=0){
            if(n1[i]>n2[j]){
                n1[k--]=n1[i--];
            }else{
                n1[k--]=n2[j--];
            }
        }
        while(j>=0){
            n1[k--]=n2[j--];
        }
        while(i>=0){
            n1[k--]=n1[i--];
        }
    }
};
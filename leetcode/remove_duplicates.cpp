/*
26. Remove Duplicates from Sorted Array
DescriptionHintsSubmissionsDiscussSolution
Given a sorted array, remove the duplicates in-place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example:

Given nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
It doesn't matter what you leave beyond the new length.
*/

class Solution {
public:
    void removeNumbers(vector<int> &nm,int i){
        if(nm.size()==0){
            return;
        }
        if(i>=nm.size()-1){
            return;
        }
        if(nm[i]==nm[i+1]){
            nm.erase(nm.begin()+i);
        }else{
            i++;
        }
        removeNumbers(nm,i);
    }
    int removeDuplicates(vector<int>& nums) {
        removeNumbers(nums,0);
        return nums.size();
    }
};
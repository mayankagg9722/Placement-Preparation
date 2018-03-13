/*
283. Move Zeroes

Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
*/
class Solution {
public:
    void moveZeroes(vector<int>& n) {
        int i=0;
        int j=0;
        while(i<n.size()){
            if(n[i]!=0){
                int t=n[j];
                n[j]=n[i];
                n[i]=t;
                j++;
                i++;
            }else{
                i++;
            }
        }
    }
};
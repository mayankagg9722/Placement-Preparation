/*
80. Remove Duplicates from Sorted Array II

Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.
*/

class Solution {
public:
     void removeNumbers(vector<int> &nm,int i,int ele,int count){
        if(nm.size()==0){
            return;
        }
        if(i>=nm.size()){
            return;
        }
        if(nm[i]==ele){
            count=count+1;
            if(count>2){
                nm.erase(nm.begin()+i);
                removeNumbers(nm,i,ele,count);
            }else{
                removeNumbers(nm,i+1,ele,count);
            }
        }else{
            ele=nm[i];
            count=0;
            removeNumbers(nm,i,ele,count);
        }
    }
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<=1){
            return nums.size();
        }
        int ele = nums[0];
        removeNumbers(nums,0,ele,0);
        return nums.size();
    }
};
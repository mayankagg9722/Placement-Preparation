/*

457. Circular Array Loop
DescriptionHintsSubmissionsDiscussSolution
You are given an array of positive and negative integers. If a number n at an index is positive, then move forward n steps. Conversely, if it's negative (-n), move backward n steps. Assume the first element of the array is forward next to the last element, and the last element is backward next to the first element. Determine if there is a loop in this array. A loop starts and ends at a particular index with more than 1 element along the loop. The loop must be "forward" or "backward'.

Example 1: Given the array [2, -1, 1, 2, 2], there is a loop, from index 0 -> 2 -> 3 -> 0.

Example 2: Given the array [-1, 2], there is no loop.

Note: The given array is guaranteed to contain no element "0".

Can you do it in O(n) time complexity and O(1) space complexity?


*/
class Solution {
public:
    bool util(vector<int> nums,int parent,vector<bool> &visited){
        if(visited[parent]){
            return true;
        }
        if(parent==nums[parent]){
            return false;
        }
        visited[parent]=true;
        if(util(nums,nums[parent],visited)){
            return true;
        }
        return false;
    }
    bool circularArrayLoop(vector<int>& nums) {
        int s = nums.size();
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0){
                nums[i]=-1*(abs(nums[i])%s);
                if(i+nums[i]<0){
                    nums[i]=s-(abs(nums[i])-i);
                }else{
                    nums[i]=i+nums[i];
                }
            }else{
                nums[i]=nums[i]%s;
                nums[i]=(i+nums[i])%s;
            }
            cout<<nums[i]<<" ";
        }
        for(int i=0;i<s;i++){
            vector<bool> visited(s,false);
            if(util(nums,i,visited)){
                return true;
            }
        }
        return false;
    }
};
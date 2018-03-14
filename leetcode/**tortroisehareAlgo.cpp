/*
287. Find the Duplicate Number
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Note:
You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).


https://www.jasondavies.com/duplicates/

##Tortoise & Haire cycle detection algorithm

  public static int findDuplicate(int[] nums) {
        //using Tortoise & Hair algorithm by Donald Knuth to find cycle in a sequence.
        //This algorithm also called Floyd's cycele detection algorithm
        int n = nums.length;
        int tortoise = n;
        int hair = n;
        
       do{
            tortoise = nums[tortoise-1];
            hair = nums[nums[hair-1]-1];
        } while(hair != tortoise);
        
        //find the starting point of the cycle
        //int mu = 0;
        tortoise = n;
        while(hair != tortoise){
            tortoise = nums[tortoise-1];
            hair = nums[hair-1];
            //mu++;
        }
        
        return tortoise;
    }


*/
class Solution {
public:
    int findDuplicate(vector<int>& n) {
        unordered_map<int,int> mp;
        for(int i:n){
            if(mp.find(i)!=mp.end()){
                return i;
            }
            mp[i]++;
        }
        //tortriose hare algorithm
        // int t=n[0];
        // int h=n[n[0]];
        // while(t!=h){
        //     t=n[t];
        //     h=n[n[h]];
        // }
        // t=0;
        // while(t!=h){
        //     t=n[t];
        //     h=n[h];
        // }
        // return t;
        return 0;
    }
};
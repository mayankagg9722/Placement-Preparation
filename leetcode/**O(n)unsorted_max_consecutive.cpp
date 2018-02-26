/*

128. Longest Consecutive Sequence

Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.


*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int c=0;
        if(nums.size()==0){
            return c;
        }
        unordered_set<int> myset(nums.begin(),nums.end());
        for(int m : nums){
            if(myset.find(m)==myset.end()){
                continue;
            }else{
                myset.erase(m);
                int prev=m-1;
                int next=m+1;
                while(myset.find(prev)!=myset.end()){
                    myset.erase(prev--);
                }
                while(myset.find(next)!=myset.end()){
                    myset.erase(next++);
                }
                c=max(c,next-prev-1);
            }
        }
        return c;
    }
};
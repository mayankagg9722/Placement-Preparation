/*
45. Jump Game II
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

Note:
You can assume that you can always reach the last index.
*/
class Solution {
public:
    int jump(vector<int>& n) {
        if(n.size()<=1){
           return 0;
        }
        if(n[0]==0){
            return -1;
        }
        int maxReach=n[0];
        int steps=n[0];
        int i=1;
        int count=1;
        for(i=1;i<n.size();i++){
            if(i>=n.size()-1){
                return count;
            }
            maxReach=max(maxReach,n[i]+i);
            steps--;
            if(steps==0){
                count++;
                steps=maxReach-i;
            }
        }
        return count;
    }
};
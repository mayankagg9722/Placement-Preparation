/*
55. Jump Game
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
*/
class Solution {
public:
    bool canJump(vector<int>& n) {
        if(n.size()<=1){
            return true;
        }
        if(n[0]==0){
            return false;
        }
        int steps=n[0];
        int maxReach=n[0];
        int jumps=1;
        int i=1;
        for(i=1;i<n.size();i++){
            if(steps==0 && i<=n.size()-1){
                return false;
            }
            if(i>=n.size()-1){
                return true;
            }
            maxReach=max(maxReach,n[i]+i);
            steps--;
            if(steps==0){
                jumps++;
                steps=maxReach-i;
            }
        }
        return false;
    }
};
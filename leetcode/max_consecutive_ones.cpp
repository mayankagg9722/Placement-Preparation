/*
485. Max Consecutive Ones

Given a binary array, find the maximum number of consecutive 1s in this array.

Example 1:
Input: [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s.
    The maximum number of consecutive 1s is 3.
Note:

The input array will only contain 0 and 1.
The length of input array is a positive integer and will not exceed 10,000

*/
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& n) {
        int s = 0;
        int i = 0;
        int ans = INT_MIN;
        while(i<n.size()){
            if(n[i]==0){
                ans=max(ans,s);
                s=0;
            }else{
                s++;
            }
            i++;
        }
        ans=max(ans,s);
        return ans;
    }
};
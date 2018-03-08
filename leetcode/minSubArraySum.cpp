/*
209. Minimum Size Subarray Sum

Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.
*/
class Solution {
public:
    int m=INT_MAX;
    int minSubArrayLen(int s, vector<int>& a) {
        if(a.size()==0){
            return 0;
        }
        int sum=0;
        int j=0,i=0;
        while(i<a.size()){
            sum+=a[i];
            while(sum>=s){
                m=min(m,i-j+1);
                sum-=a[j];
                j+=1;
            }
            i+=1;
        }
        return m==INT_MAX ? 0 : m;
    }
};
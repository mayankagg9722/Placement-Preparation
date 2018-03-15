/*
300. Longest Increasing Subsequence
Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.

Your algorithm should run in O(n2) complexity.

Follow up: Could you improve it to O(n log n) time complexity?
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& n) {
        vector<int> il;
        for(int i=0;i<n.size();i++){
            il.push_back(1);
        }
        
        for(int i=0;i<n.size();i++){
            int k = n[i];
            int m = 0;
            for(int j=0;j<i;j++){
                if(n[j]<k){
                    m=max(m,il[j]);
                }
            }
            il[i]+=m;
        }
        int m = 0;
        for(int i=0;i<n.size();i++){
            m = max(m,il[i]);
        }
        return m;
    }
};
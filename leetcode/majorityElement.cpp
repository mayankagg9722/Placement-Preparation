/*
69. Majority Element

Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.
*/

class Solution {
public:
    int majorityElement(vector<int>& N) {
        if(N.size()==0){
            return 0;
        }
        if(N.size()==1){
            return N[0];
        }
        int times = N.size()/2;
        unordered_map<int,int> myset;
        unordered_map<int, int>:: iterator p;
        for(int n:N){
            myset[n]++;
        }
        for (p = myset.begin(); p != myset.end(); p++){
            if(p->second>times){
                return p->first;
            }
        }
        return 0;
    }
};
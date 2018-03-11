/*
229. Majority Element II

**MAJORITY VOTING ALGORITHM**

=> https://gregable.com/2013/10/majority-vote-algorithm-find-majority.html

Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. The algorithm should run in linear time and in O(1) space.
*/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> a;
        int n1,n2,c1=0,c2=0;
        for(int i : nums){
            if(c1!=0 && n1==i){
                c1++;
                continue;
            }
            if(c2!=0 && n2==i){
                c2++;
                continue;
            }
            if(c1==0){
                n1=i;
                c1++;
                continue;
            }
            if(c2==0){
                n2=i;
                c2++;
                continue;
            }
            c1-=1;
            c2-=1;
        }
        int cn1=0,cn2=0;
        for(int i:nums){
            if(c1>0 && i==n1){
                cn1++;
            }
            if(c2>0 && i==n2){
                cn2++;
            }
        }
        if(cn1>nums.size()/3){
            a.push_back(n1);
        }
        if(cn2>nums.size()/3 && n1!=n2){
            a.push_back(n2);          
        }
        return a;
    }
};
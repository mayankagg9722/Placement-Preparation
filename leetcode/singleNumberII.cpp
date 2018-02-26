/*
137. Single Number II
Given an array of integers, every element appears three times except for one, which appears exactly once. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/
class Solution {
public:
    int singleNumber(vector<int>& nu) {
        unordered_set<int> ms;
        unordered_set<int> ms1;
        for(int n:nu){
            if(ms1.find(n)!=ms1.end()){
                continue;
            }else{
                if(ms.find(n)!=ms.end()){
                    ms1.insert(n);
                    ms.erase(n);
                }else{
                    ms.insert(n);
                }
            }
        }
        for(int l:ms){
            return l;
        }
        return 0;
    }
};
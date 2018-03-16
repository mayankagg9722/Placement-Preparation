/*
357. Count Numbers with Unique Digits
DescriptionHintsSubmissionsDiscussSolution
Given a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10n.

Example:
Given n = 2, return 91. (The answer should be the total numbers in the range of 0 ≤ x < 100, excluding [11,22,33,44,55,66,77,88,99])
*/
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0){
            return 1;
        }
        vector<int> a;
        if(n>=1){
            a.push_back(10);    
        }
        if(n>=2){
            a.push_back(9*9); 
        }
        int k=8;
        while(a.size()<n){
            a.push_back(a[a.size()-1]*k);
            k--;
        }
        int s=0;
        for(int i:a){
            s+=i;
        }
        return s;
    }
};
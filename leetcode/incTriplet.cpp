/*
334. Increasing Triplet Subsequence

Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

Formally the function should:
Return true if there exists i, j, k 
such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
Your algorithm should run in O(n) time complexity and O(1) space complexity.

Examples:
Given [1, 2, 3, 4, 5],
return true.

Given [5, 4, 3, 2, 1],
return false.

Credits:
Special thanks to @DjangoUnchained for adding this problem and creating all test cases.
*/
class Solution {
public:
    bool increasingTriplet(vector<int>& n) {
        vector<int> a (n.size(),1);
        if(n.size()!=0){
            int f=0;
            for(int k=0;k<n.size()-1;k++){
                if(n[k+1]>n[k]){
                    f=1;
                    break;
                }
            }
            if(f==0){
                return false;
            }
        }
        for(int i=1;i<n.size();i++){
            int m = 0;
            for(int j=0;j<i;j++){
                if(n[j]<n[i]){
                    m=max(m,a[j]);
                    if(m>=2){
                        return true;
                    }
                }
            }
            a[i]+=m;
            if(a[i]>=3){
                return true;
            }
        }
        return false;
    }
};
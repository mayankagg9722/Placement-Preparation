/*
581. Shortest Unsorted Continuous Subarray
DescriptionHintsSubmissionsDiscussSolution
Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.

You need to find the shortest such subarray and output its length.
*/
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> a=nums;
        sort(a.begin(),a.end());
        for(int k=0;k<a.size();k++){
            cout<<a[k]<<" ";
        }
        cout<<endl;
        int i=0;
        int j=nums.size()-1;
        int lb=-1;
        int ub=-1;
        while(i<j){
            if(ub!=-1 && lb!=-1){
                break;
            }
            if(a[i]!=nums[i] && lb==-1){
                lb=i;
            }else if(lb==-1){
                i++;
            }
            if(a[j]!=nums[j] && ub==-1){
                ub=j;
            }else if(ub==-1){
                j--;
            }
        }
        
        cout<<ub<<" "<<lb;
        if(ub==-1 && lb==-1){
            return 0;
        }else if(ub==-1 && lb!=-1){
            return lb+1;
        }else if(ub !=-1 && lb==-1){
            return ub+1;
        }
        return (ub-lb+1);
    }
};
/*
46. Permutations
*/
class Solution {
public:
    void swap(int i,int j,vector<int> &nums){
        int t=nums[i];
        nums[i]=nums[j];
        nums[j]=t;
    }
    void findPermutation(vector<int> &nums,int s,int l,vector<vector<int>> &p){
        if(s==l){
            p.push_back(nums);
            return;
        }
        for(int k=s;k<=l;k++){
            swap(s,k,nums);
            findPermutation(nums,s+1,l,p);
            swap(s,k,nums);
        }
    }
    vector<vector<int>> permute(vectoxr<int>& nums) {
        vector<vector<int>> p;
        findPermutation(nums,0,nums.size()-1,p);
        return p;
    }
};
class Solution {
public:
    void swap(int i,int j,vector<int> &nums){
        int t=nums[i];
        nums[i]=nums[j];
        nums[j]=t;
    }
    void findPermutation(vector<int> &nums,int s,int l,set<vector<int>> &p){
        if(s==l){
            p.insert(nums);
            return;
        }
        for(int k=s;k<=l;k++){
            swap(s,k,nums);
            findPermutation(nums,s+1,l,p);
            swap(s,k,nums);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> p;
        set<vector<int>> s;
        findPermutation(nums,0,nums.size()-1,s);
        set<vector<int>> :: iterator it;
        for(it=s.begin();it!=s.end();it++){
            p.push_back(*it);
        }
        return p;
    }
};
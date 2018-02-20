class Solution {
public:
    void putAgain(int s,int i,int val,vector<int> &nums){
        if(val<=0 || nums.size()<i || nums[i]==val){
            return;
        }
        int t = nums[i];
        nums[i]=val;
        nums[s]=t;
    }
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        if(nums.size()==0){
            return 1;
        }
        int i=0;
        while(i<nums.size()){
            if(nums[i]==i+1 || nums[i]<=0 || nums[i]>nums.size() || nums[i]==nums[nums[i]-1]){
                i++;
            }else if(i+1!=nums[i]){
                putAgain(i,nums[i]-1,nums[i],nums);
            }
        }
        for(i=0;i<nums.size();i++){
            cout<<nums[i]<<" ";
        }
        for(i=0;i<nums.size();i++){
            if(i+1!=nums[i]){
                return i+1;
            }
        }
        return n+1;
    }
};
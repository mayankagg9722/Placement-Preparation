/*
198. House Robber
DescriptionHintsSubmissionsDiscussSolution
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

TLE

class Solution {
public:
    int res=0;
    void robUtil(int st,vector<int>& nums,int s){
        if(st>=nums.size()){
            res=max(res,s);
            return;
        }
        for(int i=st;i<nums.size();i++){
            s+=nums[i];
            robUtil(i+2,nums,s);
            s-=nums[i];
        }
    }
    int rob(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            robUtil(i+2,nums,nums[i]);
        }
        return res;
    }
};

*/

class Solution {
public:
    int odd=0;
    int even=0;
    int rob(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(i%2==0){
                even = max(even+nums[i],odd);
            }else{
                odd = max(odd+nums[i],even);
            }
        }
        return max(odd,even);
    }
};




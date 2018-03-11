class Solution {
public:
    int robUtil(int s,int e,vector<int> nums){
        int odd=0;
        int even=0;
        for(int i=s;i<=e;i++){
            if(i%2==0){
                even = max(even+nums[i],odd);
            }else{
                odd = max(odd+nums[i],even);
            }
        }
        return max(even,odd);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        return max(robUtil(0,nums.size()-2,nums),robUtil(1,nums.size()-1,nums));
    }
};
/*
Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> right;
        vector<int> left;
        int i=0;
        int j=nums.size()-1;
        while(i<nums.size()){
            if(left.size()==0){
                left.push_back(nums[i]);
            }else{
                int ele = nums[i]*left[left.size()-1];
                left.push_back(ele);
            }
            if(right.size()==0){
                right.push_back(nums[j]);
            }else{
                int ele=nums[j]*right[right.size()-1];
                right.push_back(ele);
            }
            i++;
            j--;
        }
        reverse(right.begin(),right.end());
        // for(int i=0;i<left.size();i++){
        //     cout<<left[i]<<" ";
        // }
        // cout<<endl;
        // for(int i=0;i<right.size();i++){
        //     cout<<right[i]<<" ";
        // }
        if(nums.size()>0){
            nums[0]=right[1];
            nums[nums.size()-1]=left[nums.size()-2];
            for(int i=1;i<nums.size()-1;i++){
                nums[i]=left[i-1]*right[i+1];    
            }
        }
        
        
        return nums;
    }
};
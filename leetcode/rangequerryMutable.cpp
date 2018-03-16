/*
307. Range Sum Query - Mutable
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

The update(i, val) function modifies nums by updating the element at index i to val.
Example:
Given nums = [1, 3, 5]

sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8
Note:
The array is only modifiable by the update function.
You may assume the number of calls to update and sumRange function is distributed evenly


#TLE
    vector<int> a;
    NumArray(vector<int> nums) {
        a=nums;
        int s=0;
        for(int i=0;i<a.size();i++){
            s+=a[i];
            a[i]=s;
        }
    }
    
    void update(int i, int val) {
        int o=a[i];
        if(i==0){
            a[i]=val;
        }else{
            a[i]=a[i-1]+val;
        }
        int k=i+1;
        while(k<a.size()){
            int t=a[k];
            a[k]=a[k]-o+a[k-1];
            o=t;
            k++;
        }
    }
    
    int sumRange(int i, int j) {
        if(i!=0){
            return a[j]-a[i-1];
        }
        return a[j];
    }
};

*/








/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
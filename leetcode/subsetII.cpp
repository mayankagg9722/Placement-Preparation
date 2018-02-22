/*
90. Subsets II
Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        set<vector<int>> a;
        for(int i=0;i<(1<<n);i++){
            vector<int> small;
            for(int j=0;j<n;j++){
                if(i & (1<<j)){
                    small.push_back(nums[j]);
                }
            }
            a.insert(small);
        }
        vector<vector<int>> b;
        set<vector<int>> :: iterator it;
        for(it=a.begin();it!=a.end();it++){
            b.push_back(*it);
        }
        return b;
    }
};
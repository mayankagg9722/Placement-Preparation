class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> sub;
        for(int i=0;i<1<<n;i++){
            vector<int> a;
            for(int j=0;j<n;j++){
                if((i & (1<<j))){
                    a.push_back(nums[j]);
                }
            }
            sub.push_back(a);
        }
        return sub;
    }
};
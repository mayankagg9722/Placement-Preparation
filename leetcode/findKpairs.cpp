/*
373. Find K Pairs with Smallest Sums

You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.

Define a pair (u,v) which consists of one element from the first array and one element from the second array.

Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.

Example 1:
Given nums1 = [1,7,11], nums2 = [2,4,6],  k = 3

Return: [1,2],[1,4],[1,6]

The first 3 pairs are returned from the sequence:
[1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
Example 2:
Given nums1 = [1,1,2], nums2 = [1,2,3],  k = 2

Return: [1,1],[1,1]

The first 2 pairs are returned from the sequence:
[1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
Example 3:
Given nums1 = [1,2], nums2 = [3],  k = 3 

Return: [1,3],[2,3]

All possible pairs are returned from the sequence:
[1,3],[2,3]
*/
class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& n1, vector<int>& n2, int k) {
        vector<pair<int, int>> ans;
        vector<int> index(n1.size(),0);
        int tot=0;
        while(tot<k){
            int sum=INT_MAX;
            int pos=-1;
            for(int i=0;i<n1.size();i++){
                if(index[i]>=n2.size()){
                    continue;
                }
                int val=n1[i]+n2[index[i]];
                if(sum>val){
                    pos=i;
                    sum=val;
                }
            }
            if(pos!=-1){
                pair<int,int> p;
                p.first=n1[pos];
                p.second=n2[index[pos]];
                ans.push_back(p);
                index[pos]++;
                tot++;
            }else{
                break;
            }
        }
        return ans;
    }
};
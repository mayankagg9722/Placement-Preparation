/*
349. Intersection of Two Arrays
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].
*/
class Solution {
public:
    vector<int> intersection(vector<int>& n1, vector<int>& n2) {
        vector<int> a;
        unordered_map<int,int> mp;
        for(int i=0;i<n2.size();i++){
                mp[n2[i]]=1;
        }
        for(int i=0;i<n1.size();i++){
            if(mp.find(n1[i])!=mp.end() && mp.find(n1[i])->second==1){
                mp[n1[i]]=0;
                a.push_back(n1[i]);
            }
        }
        return a;
    }
};
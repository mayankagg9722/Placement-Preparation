/*
491. Increasing Subsequences

Given an integer array, your task is to find all the different possible increasing subsequences of the given array, and the length of an increasing subsequence should be at least 2 .

Example:
Input: [4, 6, 7, 7]
Output: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]
*/
class Solution {
public:
    void findsequencesUtil(vector<int> n,set<vector<int>> &a,int s,vector<int> small){
        if(small.size()>=2){
            a.insert(small);
        }
        for(int i=s;i<n.size();i++){
            if(small.size()==0 || n[i]>=small[small.size()-1]){
                small.push_back(n[i]);
                findsequencesUtil(n,a,i+1,small);
                small.pop_back();
            }
        }
        return;
    }
    vector<vector<int>> findSubsequences(vector<int>& n) {
        set<vector<int>> a;     
        vector<int> s;
        findsequencesUtil(n,a,0,s);
        set<vector<int>> :: iterator it;
        vector<vector<int>> b;
        for(it=a.begin();it!=a.end();it++){
            b.push_back(*it);
        }
        return b;
    }
};
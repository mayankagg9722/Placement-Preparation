/*
77. Combinations
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/
class Solution {
public:
    void printvector(vector<int> nr){
        for(int i=0;i<nr.size();i++){
            cout<<nr[i]<<" ";
        }
        cout<<endl;
    }
    void backtrack(vector<int> nr,int k,vector<vector<int>> &a,int s,vector<int> sm){
        if(sm.size()==k){
            // printvector(sm);
            a.push_back(sm);
            return;
        }
        for(int i=s;i<nr.size();i++){
            sm.push_back(nr[i]);
            s=i+1;
            backtrack(nr,k,a,s,sm);
            s=i-1;
            sm.pop_back();
        }
        return;
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> a;
        vector<int> nr;
        for(int i=1;i<=n;i++){
            nr.push_back(i);
        }
        vector<int> sm;
        backtrack(nr,k,a,0,sm);
        return a;
    }
};
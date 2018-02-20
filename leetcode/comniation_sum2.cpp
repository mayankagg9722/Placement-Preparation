/*

Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8, 
A solution set is: 
*/

class Solution {
public:
    void printsmall(vector<int> small){
        for(int i=0;i<small.size();i++){
            cout<<small[i]<<" ";
        }
        cout<<endl;
    }
    void findComb(vector<int>& cand, int target,set<vector<int>> &mylist,int sum,vector<int> small,vector<bool> visited){
        if(sum>target){
            return;
        }
        if(sum==target){
            sort(small.begin(),small.end());
            mylist.insert(small);   
        }
        for(int i=0;i<cand.size();i++){
            if(visited[i]==false && cand[i]<=target-sum){
                sum=sum+cand[i];
                small.push_back(cand[i]);
                visited[i]=true;
                findComb(cand,target,mylist,sum,small,visited);
                visited[i]=false;
                sum=sum-cand[i];
                small.pop_back();
            }else{
                break;
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& cand, int target) {
        
        set<vector<int>> mylist;
        vector<vector<int>> t;
        
        sort(cand.begin(),cand.end());
        
        vector<bool> visited;
        for(int i=0;i<cand.size();i++){
            if(cand[i]>target){
                 visited.push_back(true);
            }else{
                visited.push_back(false);
            }
        }
        
        vector<int> small;
        int sum=0;
        
        findComb(cand,target,mylist,sum,small,visited);
        

        set<vector<int>> :: iterator it;
        for(it=mylist.begin();it!=mylist.end();it++){
            t.push_back(*it);
        }
        return t;
    }
};
/*
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.


Example 1:

Input: k = 3, n = 7

Output:

[[1,2,4]]
*/

class Solution {
public:
    void printsmall(vector<int> small){
        for(int i=0;i<small.size();i++){
            cout<<small[i]<<" ";
        }
        cout<<endl;
    }
    void findComb(vector<int>& cand, int target,set<vector<int>> &mylist,int sum,vector<int> small,vector<bool> visited,int k){
        if(sum==target && k==0){
            sort(small.begin(),small.end());
            mylist.insert(small);   
        }
        if(k==0){
            return;
        }
        if(sum>target){
            return;
        }
        
        for(int i=0;i<cand.size();i++){
            if(visited[i]==false && cand[i]<=target-sum){
                k=k-1;
                sum=sum+cand[i];
                small.push_back(cand[i]);
                visited[i]=true;
                findComb(cand,target,mylist,sum,small,visited,k);
                k=k+1;
                visited[i]=false;
                sum=sum-cand[i];
                small.pop_back();
            }else{
                break;
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int target) {
        set<vector<int>> mylist;
        vector<vector<int>> t;
        vector<int> cand;
        for(int i=0;i<9;i++){
            cand.push_back(i+1);
        }
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
        
        findComb(cand,target,mylist,sum,small,visited,k);
        
        set<vector<int>> :: iterator it;
        for(it=mylist.begin();it!=mylist.end();it++){
            t.push_back(*it);
        }
        return t;
    }
};
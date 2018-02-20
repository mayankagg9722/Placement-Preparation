class Solution {
public:
    void printsmall(vector<int> small){
        for(int i=0;i<small.size();i++){
            cout<<small[i]<<" ";
        }
        cout<<endl;
    }
    void findComb(vector<int>& cand, int target,set<vector<int>> &mylist,int sum,vector<int> small){
        if(sum>target){
            return;
        }
        if(sum==target){
            sort(small.begin(),small.end());
            mylist.insert(small);   
        }
        for(int i=0;i<cand.size();i++){
            sum=sum+cand[i];
            small.push_back(cand[i]);
            findComb(cand,target,mylist,sum,small);
            sum=sum-cand[i];
            small.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& cand, int target) {
        set<vector<int>> mylist;
        vector<vector<int>> t;
        vector<int> small;
        int sum=0;
        findComb(cand,target,mylist,sum,small);
        set<vector<int>> :: iterator it;
        for(it=mylist.begin();it!=mylist.end();it++){
            t.push_back(*it);
        }
        return t;
    }
};
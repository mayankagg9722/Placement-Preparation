/*
378. Kth Smallest Element in a Sorted Matrix

Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Example:

matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

return 13.
Note: 
You may assume k is always valid, 1 ≤ k ≤ n2.
*/
class Solution {
public:
    int r,c;
    bool safe(int i,int j){
        if(i>=0 && j>=0 && i<r && j<c){
            return true;
        }
        return false;
    }
    int kthSmallest(vector<vector<int>>& m, int k) {
        r = m.size();
        if(r==0){
            return 0;
        }
        c = m[0].size();
        if(c==0){
            return 0;
        }
        vector<int> a;
        vector<pair<int,int>> q;
        vector<pair<int,int>> :: iterator it;
        vector<pair<int,int>> :: iterator pos;
        pair<int,int> p (0,0);
        q.push_back(p);
        while(q.size()!=0 && a.size()<k){
            int s=INT_MAX;
            for(it=q.begin();it!=q.end();it++){
                int val = m[(*it).first][(*it).second];
                if(s>val){
                    s=m[(*it).first][(*it).second];
                    pos=it;
                }
            }
            if(s!=INT_MAX){
                a.push_back(s);
                int i = (*pos).first;
                int j = (*pos).second;
                q.erase(pos);
                if(safe(i,j+1)){
                    pair<int,int> p (i,j+1);
                    if(find(q.begin(),q.end(),p)==q.end()){
                        q.push_back(p);    
                    }
                }
                if(safe(i+1,j)){
                    pair<int,int> p (i+1,j);
                    if(find(q.begin(),q.end(),p)==q.end()){
                        q.push_back(p);    
                    }
                }
            }
        }
        return a[a.size()-1];
    }
};
/*
417. Pacific Atlantic Water Flow
DescriptionHintsSubmissionsDiscussSolution
Given an m x n matrix of non-negative integers representing the height of each unit cell in a continent, the "Pacific ocean" touches the left and top edges of the matrix and the "Atlantic ocean" touches the right and bottom edges.

Water can only flow in four directions (up, down, left, or right) from a cell to another one with height equal or lower.

Find the list of grid coordinates where water can flow to both the Pacific and Atlantic ocean.

Note:
The order of returned grid coordinates does not matter.
Both m and n are less than 150.
Example:

Given the following 5x5 matrix:

  Pacific ~   ~   ~   ~   ~ 
       ~  1   2   2   3  (5) *
       ~  3   2   3  (4) (4) *
       ~  2   4  (5)  3   1  *
       ~ (6) (7)  1   4   5  *
       ~ (5)  1   1   2   4  *
          *   *   *   *   * Atlantic

Return:

[[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (positions with parentheses in above matrix).
*/
class Solution {
public:
    int r,c;
    bool safe(vector<vector<int>> a,int i,int j,int ni,int nj,vector<vector<int>>& s){
        if(i>=0 && j>=0 && i<r && j<c && a[i][j]>=a[ni][nj] && s[i][j]==0){
            s[i][j]=1;
            return true;
        }
        return false;
    }
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& m) {
        vector<pair<int, int>> ans;
        r=m.size();
        if(r==0){
            return ans;
        }
        c=m[0].size();
        vector<vector<int>> pacific(r,vector<int>(c,0));
        vector<vector<int>> antartic(r,vector<int>(c,0));
        stack<pair<int,int>> sp;
        stack<pair<int,int>> sa;
        for(int i=0;i<r;i++){
            pacific[i][0]=1;
            sp.push(make_pair(i,0));
            antartic[i][c-1]=1;
            sa.push(make_pair(i,c-1));
        }
        for(int j=0;j<c;j++){
            pacific[0][j]=1;
            sp.push(make_pair(0,j));
            antartic[r-1][j]=1;
            sa.push(make_pair(r-1,j));
        }
        
        while(!sp.empty()){
            pair<int,int> w = sp.top();
            int i = w.first;
            int j = w.second;
            sp.pop();
            if(safe(m,i+1,j,i,j,pacific)){
                sp.push(make_pair(i+1,j));
            }
            if(safe(m,i-1,j,i,j,pacific)){
                sp.push(make_pair(i-1,j));
            }
            if(safe(m,i,j+1,i,j,pacific)){
                sp.push(make_pair(i,j+1));
            }
            if(safe(m,i,j-1,i,j,pacific)){
                sp.push(make_pair(i,j-1));
            }
        }
        
        while(!sa.empty()){
            pair<int,int> w = sa.top();
            int i = w.first;
            int j = w.second;
            sa.pop();
            if(safe(m,i+1,j,i,j,antartic)){
                sa.push(make_pair(i+1,j));
            }
            if(safe(m,i-1,j,i,j,antartic)){
                sa.push(make_pair(i-1,j));
            }
            if(safe(m,i,j+1,i,j,antartic)){
                sa.push(make_pair(i,j+1));
            }
            if(safe(m,i,j-1,i,j,antartic)){
                sa.push(make_pair(i,j-1));
            }
        }
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(pacific[i][j]==1 && antartic[i][j]==1){  
                    ans.push_back(pair<int,int>(i,j));
                }
            }
        }
        return ans;
    }
};
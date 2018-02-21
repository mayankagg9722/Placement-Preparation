/*
63. Unique Paths II
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.
*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> nm;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        for(int i=0;i<m;i++){
            vector<int> sm;
            for(int j=0;j<n;j++){
                if(obstacleGrid[i][j]==1){
                    sm.push_back(-1);
                }else{
                    sm.push_back(0);
                }
            }
            nm.push_back(sm);
        }
        if(nm[0][0]==-1){
            nm[0][0]=-1;
        }else{
            nm[0][0]=1;    
        }
        for(int i=1;i<n;i++){
            if(nm[0][i]!=-1){
                nm[0][i]=nm[0][i-1];
            }
        }
        for(int i=1;i<m;i++){
            if(nm[i][0]!=-1){
                nm[i][0]=nm[i-1][0];
            }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(nm[i][j]!=-1 && nm[i-1][j]!=-1){
                    nm[i][j]+=nm[i-1][j];
                }
                if(nm[i][j]!=-1 && nm[i][j-1]!=-1){
                    nm[i][j]+=nm[i][j-1];
                }
            }
        }
        if(nm[m-1][n-1]==-1){
            return 0;
        }
        return nm[m-1][n-1];
    }
};
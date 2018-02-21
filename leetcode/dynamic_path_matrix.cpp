class Solution {
public:
     int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> nm=grid;
         for(int i=0;i<grid.size();i++){
             for(int j=0;j<grid[0].size();j++){
                 nm[i][j]=-1;
             }
         }
         nm[0][0]=grid[0][0];
         for(int i=1;i<grid[0].size();i++){
             nm[0][i]=grid[0][i]+nm[0][i-1];
         }
         for(int i=1;i<grid.size();i++){
             nm[i][0]=grid[i][0]+nm[i-1][0];
         }
         for(int i=1;i<grid.size();i++){
             for(int j=1;j<grid[0].size();j++){
                 nm[i][j]=min(nm[i-1][j],nm[i][j-1])+grid[i][j];
             }
         }
        return nm[grid.size()-1][grid[0].size()-1];
    }
};
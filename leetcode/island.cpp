/*
200. Number of Islands

Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000
Answer: 1

Example 2:

11000
11000
00100
00011
*/
class Solution {
public:
    int r,c;
    bool safe(int i,int j,vector<vector<char>> grid){
        if(i>=0 && j>=0 && i<r && j<c && grid[i][j]=='1'){
            return true;
        }
        return false;
    }
    void checkisland(int i,int j,vector<vector<char>>& grid){
        if(i<0 || j<0 || i>=r || j>=c){
             return;
        }
        grid[i][j]='2';
        if(safe(i+1,j,grid)){
            checkisland(i+1,j,grid);
        }       
        if(safe(i-1,j,grid)){
            checkisland(i-1,j,grid);
        }
        if(safe(i,j-1,grid)){
            checkisland(i,j-1,grid);
        }
        if(safe(i,j+1,grid)){
            checkisland(i,j+1,grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        r=grid.size();
        if(r==0){
            return 0;
        }
        c=grid[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]=='1'){
                    count+=1;
                    checkisland(i,j,grid);   
                }   
            }
        }
        return count;
    }
};
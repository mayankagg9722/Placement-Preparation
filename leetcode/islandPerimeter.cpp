/*
463. Island Perimeter
DescriptionHintsSubmissionsDiscussSolution
You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water. Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells). The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

Example:

[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]

Answer: 16
Explanation: The perimeter is the 16 yellow stripes in the image below:

*/

// There is no such test case of a seprate islan there is onle and only one islan in whole matrix
 
class Solution {
public:
    int r,c;
    int islandPerimeter(vector<vector<int>>& grid) {
        r=grid.size();
        if(r==0){
            return 0;
        }
        c=grid[0].size();
        int perimeter=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1){
                    perimeter += 4;
                    if (i > 0 && grid[i - 1][j] == 1) {
                        perimeter -= 1;
                    }
                    if (i + 1 < r && grid[i + 1][j] == 1) {
                        perimeter -= 1;
                    }
                    if (j > 0 && grid[i][j - 1] == 1) {
                        perimeter -= 1;
                    }
                    if (j + 1 < c && grid[i][j + 1] == 1) {
                        perimeter -= 1;
                    }
                }
            }
        }
        return perimeter;
    }
};

// #################    TLE. ########################

// class Solution {
// public:
//     int r,c;
//     int maxcount=0;
//     int count=0;
//     bool safe(int i,int j,vector<vector<int>> grid){
//         if(i>=0 && j>=0 && i<r && j<c && grid[i][j]==1){
//             return true;
//         }
//         return false;
//     }
//     int getPerimeter(int i,int j,vector<vector<int>> a){
//         int p=0;
//         if(i+1==r || a[i+1][j]==0){
//             p+=1;
//         }
//         if(i==0 || a[i-1][j]==0){
//             p+=1;
//         }
//         if(j+1==c || a[i][j+1]==0){
//             p+=1;
//         }
//         if(j==0 || a[i][j-1]==0){
//             p+=1;
//         }
//         return p;
//     }
//     void gridutil(vector<vector<int>> &grid,int i,int j){
//         if(i<0 || j<0 || i>=r || j>=c){
//             return;
//         }
//         grid[i][j]=-1;
//         int k=getPerimeter(i,j,grid);
//         count=count+k;
//         if(safe(i+1,j,grid)){
//             gridutil(grid,i+1,j);
//         }
//         if(safe(i-1,j,grid)){
//             gridutil(grid,i-1,j);
//         }
//         if(safe(i,j+1,grid)){
//             gridutil(grid,i,j+1);
//         }
//         if(safe(i,j-1,grid)){
//             gridutil(grid,i,j-1);
//         }
//     }
//     int islandPerimeter(vector<vector<int>>& grid) {
//         r=grid.size();
//         if(r==0){
//             return 0;
//         }
//         c=grid[0].size();
//         for(int i=0;i<r;i++){
//             for(int j=0;j<c;j++){
//                 if(grid[i][j]==1){
//                     count=0;
//                     gridutil(grid,i,j);
//                     maxcount=max(maxcount,count);
//                 }
//             }
//         }
//         return maxcount;
//     }
// };




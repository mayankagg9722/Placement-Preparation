/*
289. Game of Life

According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies, as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population..
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
Write a function to compute the next state (after one update) of the board given its current state.

Follow up: 
Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.
In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?
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
    void gameOfLife(vector<vector<int>>& a) {
        r=a.size();
        if(r==0){
            return;
        }
        c=a[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                int l=0;
                if(safe(i+1,j)){
                    if(a[i+1][j]==1 || a[i+1][j]==2){
                        l++;
                    }
                }
                if(safe(i-1,j)){
                    if(a[i-1][j]==1 || a[i-1][j]==2){
                        l++;
                    }
                }
                if(safe(i,j+1)){
                    if(a[i][j+1]==1 || a[i][j+1]==2){
                        l++;
                    }
                }
                if(safe(i,j-1)){
                    if(a[i][j-1]==1 || a[i][j-1]==2){
                        l++;
                    }
                }
                if(safe(i+1,j+1)){
                    if(a[i+1][j+1]==1 || a[i+1][j+1]==2){
                        l++;
                    }
                }
                if(safe(i+1,j-1)){
                    if(a[i+1][j-1]==1 || a[i+1][j-1]==2){
                        l++;
                    }
                }
                if(safe(i-1,j-1)){
                    if(a[i-1][j-1]==1 || a[i-1][j-1]==2){
                        l++;
                    }
                }
                if(safe(i-1,j+1)){
                    if(a[i-1][j+1]==1 || a[i-1][j+1]==2){
                        l++;
                    }
                }
                
                if(a[i][j]==1 && (l<2 || l>3)){
                    a[i][j]=2;
                }
                if(a[i][j]==0 && l==3){
                    a[i][j]=3;
                }
            }
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                a[i][j]=a[i][j]%2;
            }
        }
    }
};
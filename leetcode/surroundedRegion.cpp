/*
130. Surrounded Regions

Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
*/
class Solution {
public:
    int r,c;
    void check(int i,int j,vector<vector<char>>& board){
        if(i<0 || j<0 || j>=c || i>=r){
            return;
        }
        if(board[i][j]=='O'){
            board[i][j]='N';
            check(i+1,j,board);
            check(i-1,j,board);
            check(i,j+1,board);
            check(i,j-1,board);
        }
    }
    void solve(vector<vector<char>>& board){
        if(board.size()==0){
            return;
        }
        r=board.size();
        c=board[0].size();
        for(int i=0;i<r;i++){
            check(i,0,board);
        }
        for(int i=0;i<r;i++){
            check(i,c-1,board);
        }
        for(int i=0;i<c;i++){
            check(0,i,board);
        }
        for(int i=0;i<c;i++){
            check(r-1,i,board);
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(board[i][j]=='N'){
                    board[i][j]='O';
                }else{
                    board[i][j]='X';
                }
            }
        }
    }
};
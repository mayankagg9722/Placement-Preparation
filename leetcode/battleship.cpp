/*
419. Battleships in a Board

Given an 2D board, count how many battleships are in it. The battleships are represented with 'X's, empty slots are represented with '.'s. You may assume the following rules:
You receive a valid board, made of only battleships or empty slots.
Battleships can only be placed horizontally or vertically. In other words, they can only be made of the shape 1xN (1 row, N columns) or Nx1 (N rows, 1 column), where N can be of any size.
At least one horizontal or vertical cell separates between two battleships - there are no adjacent battleships.
Example:
X..X
...X
...X
In the above board there are 2 battleships.
Invalid Example:
...X
XXXX
...X
This is an invalid board that you will not receive - as battleships will always have a cell separating between them.
Follow up:
Could you do it in one-pass, using only O(1) extra memory and without modifying the value of the board?
*/
class Solution {
public:
    int r,c;
    int count=0;
    void util(vector<vector<char>>& b,int i,int j){
        b[i][j]='*';
        int k=j+1;
        while(k<c && b[i][k]=='X'){
            if(b[i][k]=='.' || b[i][k]=='*'){
                break;
            }
            b[i][k]='*';
            k++;
        }
        k=i+1;
        while(k<r && b[k][j]=='X'){
            if(b[k][j]=='.' || b[k][j]=='*'){
                break;
            }
            cout<<i<<" "<<k<<endl;
            b[k][j]='*';
            k++;
        }
    }
    int countBattleships(vector<vector<char>>& b) {
        r=b.size();
        if(r==0){
            return 0;
        }
        c=b[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(b[i][j]=='X'){
                    count+=1;
                    util(b,i,j);
                }
            }
        }
        return count;
    }
};
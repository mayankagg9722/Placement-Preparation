/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/

class Solution {
public:
    bool safe(vector<vector<char>>& board,vector<vector<bool>>& visited,int i,int j,char next,int f){
        if(i>=0 && i<board.size() && j>=0 && j<board[0].size() && board[i][j]==next && visited[i][j]==false && f==0){
            return true;
        }
        return false;
    }
    bool existUtil(vector<vector<char>>& board,vector<vector<bool>>& visited,int i,int j,int k,string word,int &f){
        if(k==word.length()-1){
            f=1;
            return true;
        }
        visited[i][j]=true;
        k=k+1;
        if(safe(board,visited,i+1,j,word[k],f)){
            existUtil(board,visited,i+1,j,k,word,f);
        }
        if(safe(board,visited,i-1,j,word[k],f)){
            existUtil(board,visited,i-1,j,k,word,f);
        }
        if(safe(board,visited,i,j+1,word[k],f)){
            existUtil(board,visited,i,j+1,k,word,f);
        }
        if(safe(board,visited,i,j-1,word[k],f)){
            existUtil(board,visited,i,j-1,k,word,f);
        }
        if(f==1){
            return true;
        }
        visited[i][j]=false;
        k=k-1;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited;
        for(int i=0;i<board.size();i++){
            vector<bool> a;
            for(int j=0;j<board[i].size();j++){
                a.push_back(false);
            }
            visited.push_back(a);
        }
        if(word.length()==0){
            return true;
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                int k=0;
                int f=0;
                if(board[i][j]==word[0]){
                    existUtil(board,visited,i,j,k,word,f);
                    if(f==1){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
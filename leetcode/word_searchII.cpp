/*
212. Word Search II
DescriptionHintsSubmissionsDiscussSolution
Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

For example,
Given words = ["oath","pea","eat","rain"] and board =

[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
Return ["eat","oath"].
*/
class Solution {
public:
    int r,c;
    vector<string> v;
    bool safe(int i,int j,vector<vector<bool>> visited,string nw,string w,vector<vector<char>> board){
        if(i>=0 && j>=0 && i<r && j<c && board[i][j]==w[nw.length()] && visited[i][j]==false && nw.length() < w.length()){
            return true;
        }
        return false;
    }
    bool findUtil(vector<vector<char>>& board,vector<vector<bool>>& visited,string w,string nw,int i,int j){
        
        visited[i][j]=true;
        nw+=board[i][j];

        if(safe(i+1,j,visited,nw,w,board)){
            if(findUtil(board,visited,w,nw,i+1,j)){
                return true;
            }
        }
        if(safe(i-1,j,visited,nw,w,board)){
            if(findUtil(board,visited,w,nw,i-1,j)){
                return true;
            }
        }
        if(safe(i,j+1,visited,nw,w,board)){
            if(findUtil(board,visited,w,nw,i,j+1)){
                return true;
            }
        }
        if(safe(i,j-1,visited,nw,w,board)){
            if(findUtil(board,visited,w,nw,i,j-1)){
                return true;
            }
        }
        
        if(nw==w){
            v.push_back(w);
            return true;
        }
        
        visited[i][j]=false;
        nw.pop_back();
        return false;
    }
    void makeVisited(vector<vector<bool>>& visited){
        for(int i=0;i<r;i++){
            vector<bool> e;
            for(int j=0;j<c;j++){
                e.push_back(false);
            }
            visited.push_back(e);
        }
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        r=board.size();
        if(r==0){
            return v;
        }
        c=board[0].size();
        sort(words.begin(),words.end());
        for(int i=0;i<words.size();i++){
            vector<vector<bool>> visited;
            makeVisited(visited);
            int f=0;
            for(int p=0;p<r;p++){
                for(int q=0;q<c;q++){
                    if(visited[p][q]==false && words[i][0]==board[p][q]){
                        string k;
                        if(findUtil(board,visited,words[i],k,p,q)){
                            f=1;
                            break;
                        }
                    }
                }
                if(f==1){
                    break;
                }
            }
        }
        return v;
    }
};
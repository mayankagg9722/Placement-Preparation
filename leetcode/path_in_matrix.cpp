class Solution {
public:
    int t=INT_MAX;
    bool safe(int i,int j,vector<vector<bool>> &visited,int mi,int mj){
        if(i>=0 && i<mi && j>=0 && j<mj && visited[i][j]==false){
            return true;
        }
        return false;
    }
    void findPath(int i,int j,int s,int mi,int mj,vector<vector<bool>> &visited,vector<vector<int>> grid){
        
        if(i<0 || i>=mi || j<0 || j>=mj){
            return;
        }
        
        if(i==mi-1 && j==mj-1){
            t=min(t,s);
            // cout<<"t:"<<t<<endl;
            return;
        }
        
        // if(safe(i,j+1,visited,mi,mj) && safe(i+1,j,visited,mi,mj)){
        //     if(grid[i+1][j]>=grid[i][j+1]){
        //         visited[i][j+1]=true;
        //         s=s+grid[i][j+1];
        //         findPath(i,j+1,s,mi,mj,visited,grid);
        //         visited[i][j+1]=false;
        //         s=s-grid[i][j+1];
        //     }else if(grid[i+1][j]<grid[i][j+1]){
        //         visited[i+1][j]=true;
        //         s=s+grid[i+1][j];
        //         findPath(i+1,j,s,mi,mj,visited,grid);
        //         visited[i+1][j]=false;
        //         s=s-grid[i+1][j];
        //     }
        // }else if(safe(i,j+1,visited,mi,mj) && !safe(i+1,j,visited,mi,mj)){
        //     visited[i][j+1]=true;
        //     s=s+grid[i][j+1];
        //     findPath(i,j+1,s,mi,mj,visited,grid);
        //     visited[i][j+1]=false;
        //     s=s-grid[i][j+1];
        // }else if(!safe(i,j+1,visited,mi,mj) && safe(i+1,j,visited,mi,mj)){
        //     visited[i+1][j]=true;
        //     s=s+grid[i+1][j];
        //     findPath(i+1,j,s,mi,mj,visited,grid);
        //     visited[i+1][j]=false;
        //     s=s-grid[i+1][j];
        // }
      
        if(safe(i+1,j,visited,mi,mj)){
            visited[i+1][j]=true;
            s=s+grid[i+1][j];
            findPath(i+1,j,s,mi,mj,visited,grid);
            visited[i+1][j]=false;
            s=s-grid[i+1][j];
        }
        
        if(safe(i,j+1,visited,mi,mj)){
            visited[i][j+1]=true;
            s=s+grid[i][j+1];
            findPath(i,j+1,s,mi,mj,visited,grid);
            visited[i][j+1]=false;
            s=s-grid[i][j+1];
        }
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<bool>> visited;
        for(int i=0;i<grid.size();i++){
            vector<bool> f;
            for(int j=0;j<grid[i].size();j++){
                f.push_back(false);
            }
            visited.push_back(f);
        }
        int maxI=grid.size();
        int maxJ=grid[0].size();
        visited[0][0]=true;
        findPath(0,0,grid[0][0],maxI,maxJ,visited,grid);
        return t;
    }
};
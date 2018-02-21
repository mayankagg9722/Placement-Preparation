class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> nm;
        for(int i=0;i<m;i++){
            vector<int> sm;
            for(int j=0;j<n;j++){
                sm.push_back(-1);
            }
            nm.push_back(sm);
        }
        nm[0][0]=1;
        for(int i=0;i<n;i++){
            nm[0][i]=1;
        }
        for(int i=0;i<m;i++){
            nm[i][0]=1;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                nm[i][j]=nm[i-1][j]+nm[i][j-1];
            }
        }
        return nm[m-1][n-1];
    }
};
class Solution {
public:
    void rotate(vector<vector<int>>& m) {
        int s = m.size();
        for(int i=0;i<s;i++){
            for(int j=0;j<s;j++){
                if(i<j){
                    int t=m[i][j];
                    m[i][j]=m[j][i];
                    m[j][i]=t;
                }
            }
        }
        int i=0;
        int j=s-1;
        while(i<j){
            for(int k=0;k<s;k++){
                int t=m[k][i];
                m[k][i]=m[k][j];
                m[k][j]=t;
            }
            i++;
            j--;
        }
    }
};
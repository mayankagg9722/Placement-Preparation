class Solution {
public:
    int findHorizontal(vector<vector<char>>& a,int i,int j){
        int c=1;
        for(int k=j;k<a[i].size()-1;k++){
            if(a[i][k]==a[i][k+1] && a[i][k]=='1'){
                c++;
            }else{
                break;
            }
        }
        return c;
    }
    int findVertical(vector<vector<char>>& a,int i,int j,int h){
        int c=1;
        for(int k=i+1;k<a.size();k++){
            if(a[k][j]!='1'){
                break;
            }
            int t=findHorizontal(a,k,j);
            if(t>=h){
                if(a[k][j]=='1'){
                    c++;
                }
            }else{
                break;
            }
        }
        for(int k=i-1;k>=0;k--){
            if(a[k][j]!='1'){
                break;
            }
            int t=findHorizontal(a,k,j);
            if(t>=h){
                if(a[k][j]=='1'){
                    c++;
                }
            }else{
                break;
            }
        }
        return c;        
    }
    int maximalRectangleUtil(vector<vector<char>>& a) {
        int max=0;
        for(int i=0;i<a.size();i++){
            for(int j=0;j<a[i].size();j++){
                if(a[i][j]=='1'){
                    int h=findHorizontal(a,i,j);
                    int v=findVertical(a,i,j,h);
                    if(max<(h*v)){
                        max=h*v;
                    }   
                }
            }
        }
        return max;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int max=maximalRectangleUtil(matrix);
        return max;
    }
};
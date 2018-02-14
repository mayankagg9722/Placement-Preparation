class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int target) {
        for(int i=0;i<a.size();i++){
            if(a[i].size()==0){
                continue;
            }
            int p=0;
            int q=a[i].size()-1;
            if(target==a[i][p] || target==a[i][q]){
                return true;
            }else if(target>a[i][p] && target<a[i][q]){
                cout<<"w1"<<endl;
                for(int j=0;j<a[i].size();j++){
                    cout<<a[i][j]<<" ";
                    if(a[i][j]==target){
                        return true;
                    }
                }
                return false;
            }else if(target>a[i][q]){
                continue;
            }
        }
        return false;
    }
};
class Solution {
public:
    void setZeroes(vector<vector<int>>& a) {
        vector<int> pos;
        for(int i=0;i<a.size();i++){
            int f=0;
            for(int j=0;j<a[i].size();j++){
                if(a[i][j]==0){
                    f=1;
                    pos.push_back(j);
                }
            }
            if(f==1){
                for(int t=0;t<a[i].size();t++){
                    a[i][t]=0;
                }
            }
        }
        for(int i=0;i<a.size();i++){
            for(int t=0;t<pos.size();t++){
                a[i][pos[t]]=0;
            }
        }
    }
};
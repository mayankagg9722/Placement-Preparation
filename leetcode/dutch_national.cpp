class Solution {
public:
    void sortColors(vector<int>& a) {
        int i=0;
        int j=a.size()-1;
        int k=0;
        while(k<=j){
            if(a[k]==0 && i!=k){
                int t=a[i];
                a[i]=a[k];
                a[k]=t;
                i++;
            }else if(a[k]==2 && j!=k){
                int t=a[j];
                a[j]=a[k];
                a[k]=t;
                j--;
            }else{
                k++;
            }   
        }
    }
};
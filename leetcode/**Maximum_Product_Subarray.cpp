// Find the contiguous subarray within an array (containing at least one number) which has the largest product.

// For example, given the array [2,3,-2,4],
// the contiguous subarray [2,3] has the largest product = 6.


class Solution {
public:
    int maxProduct(vector<int>& a) {
        int m=a[0];
        int imax=a[0];
        int imin=a[0];
        for(int i=1;i<a.size();i++){
            if(a[i]<=0){
                int t=imax;
                imax=imin;
                imin=t;
            }
            imax=max(a[i],imax*a[i]);
            imin=min(a[i],imin*a[i]);
            cout<<"imax:"<<imax<<endl;
            cout<<"imin:"<<imin<<endl;
            m=max(m,imax);
        }
        return m;
    }
};
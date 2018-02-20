class Solution {
public:
    int maxSubArray(vector<int>& a) {
        int m=a[0];
        int maxtill=a[0];
        for(int i=1;i<a.size();i++){
            maxtill=max(a[i],a[i]+maxtill);
            m=max(m,maxtill);
        }
        return m;
    }
};
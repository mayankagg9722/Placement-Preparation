/*

368. Largest Divisible Subset

Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies: Si % Sj = 0 or Sj % Si = 0.

If there are multiple solutions, return any subset is fine.

Example 1:

nums: [1,2,3]

Result: [1,2] (of course, [1,3] will also be ok)
Example 2:

nums: [1,2,4,8]

Result: [1,2,4,8]
*/
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& n) {
        vector<int> b;
        if(n.size()==0){
            return b;
        }
        sort(n.begin(),n.end());
        vector<int> a (n.size(),1);
        a[0]=1;
        for(int i=1;i<a.size();i++){
            for(int j=i-1;j>=0;j--){
                if(n[i]%n[j]==0){
                    a[i]=max(a[i],a[j]+1);
                }
            }
        }
        int maxindex=0;
        for(int i=1;i<a.size();i++){
            if(a[i]>a[maxindex]){
                maxindex=i;
            }
        }
        int t = n[maxindex];
        int c = a[maxindex];
        cout<<t<<" "<<c<<endl;
        for(int i=maxindex;i>=0;i--){
            if(t%n[i]==0 && a[i]==c){
                b.push_back(n[i]);
                t=n[i];
                c=c-1;
            }
        }
        reverse(b.begin(),b.end());
        return b;
    }
};
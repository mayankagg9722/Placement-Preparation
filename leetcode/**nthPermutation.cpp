/*
60. Permutation Sequence
Given n and k, return the kth permutation sequence.
*/

class Solution {
public:
    void swap(int i,int j,vector<int> &s ){
        int t=s[i];
        s[i]=s[j];
        s[j]=t;
    }
    void nextPermutation(vector<int> &s){
        int k=-1;
        for(int i=s.size()-2;i>=0;i--){
            if(s[i]<s[i+1]){
                k=i;
                break;
            }
        }
        if(k==-1){
            reverse(s.begin(),s.end());
            return;
        }
        int l=-1;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]>s[k]){
                l=i;
                break;
            }
        }
        swap(k,l,s);
        reverse(s.begin()+k+1,s.end());
    }
    string getPermutation(int n, int k) {
        vector<int> s;
        string mystr;
        for(int i=1;i<=n;i++){
            mystr.append(to_string(i));
            s.push_back(i);
        }
        for(int i=2;i<=k;i++){
            nextPermutation(s);
        }
        mystr.clear();
        for(int i=0;i<s.size();i++){
            mystr.append(to_string(s[i]));
        }
        return mystr;
    }
};
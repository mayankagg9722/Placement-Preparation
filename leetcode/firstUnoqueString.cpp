class Solution {
public:
    int firstUniqChar(string s) {
       int a[26];
        for(int i=0;i<26;i++){
            a[i]=0;
        }
        for(int i : s){
            a[i-97]++;
        }
        int k=0;
        for(int i : s){
            if(a[i-97]==1){
                return k;
            }
            k++;
        }
        return -1;
    }
};
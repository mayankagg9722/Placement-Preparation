/*
151. Reverse Words in a String

Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".
*/

class Solution {
public:
    int findIndex(string &s,int j){
        while(s[j]!=' ' && j<s.length()){
            j++;
        }
        return j;
    }
    void reverseEach(string &s){
        int i=0;
        while(i<s.length()){
            int j=findIndex(s,i);
            reverse(s.begin()+i,s.begin()+j);
            i=j;
            while(i<s.length() && s[i]==' '){
                i++;
            }
        }
    }
    void trimStart(string &s){
        int f=0;
        int k=0;
        while(s[k]==' ' && k < s.length()){
            f=1;
            k++;
        }
        if(f!=0)
        s.erase(s.begin(),s.begin()+k);
    }
    void trimEnd(string &s){
        int k=s.length()-1;
        int f=0;
        while(s[k]==' ' && k< s.length()){
            f=1;
            k--;
        }
        if(f!=0)
        s.erase(s.begin()+k+1,s.end());
    }
    void trimBetween(string &s,int k){
        if(k>=s.length()){
            return;
        }
        while(s[k]!=' ' && k < s.length()){
            k++;
        }
        int sn=k;
        int count=0;
        int f=0;
        while(s[k]==' ' && k < s.length()){
            f=1;
            k++;
        }
        if(f!=0){
            s.erase(s.begin()+sn,s.begin()+k-1);  
        }
        trimBetween(s,k);
    }
    void reverseWords(string &s) {
        reverse(s.begin(),s.end());
        reverseEach(s);
        trimStart(s);
        trimEnd(s);
        trimBetween(s,0);
    }
};
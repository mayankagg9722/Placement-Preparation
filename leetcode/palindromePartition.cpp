/*
132. Palindrome Partitioning II (TLE)
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
*/
class Solution {
public:
    int t=INT_MAX;
    bool checkPalindrome(string st,int s,int e){
        while(s<=e){
            if(st[s]!=st[e]){
                return false;
            }
            s++;
            e--;
        }
        return true;
    }
    void findMin(string s,int i,int m){
        if(i==s.length()){
            cout<<"m:"<<m<<endl;
            t=min(t,m);
            return;
        }
        for(int k=i;k<s.length();k++){
            if(checkPalindrome(s,i,k)){
                m=m+1;
                findMin(s,k+1,m);
                m=m-1;
            }
        }
    }
    int minCut(string s) {
        if(s.length()==0){
            return 0;
        }
        findMin(s,0,0);
        return t-1;
    }
};
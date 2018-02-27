/*
131. Palindrome Partitioning

Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

[
  ["aa","b"],
  ["a","a","b"]
]
*/
class Solution {
public:
    bool checkpalindrome(string s,int st,int en){
        int i=st,j=en;
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void findUtil(string s,vector<vector<string>> &a,int i,vector<string>& small){
        if(i==s.length()){
            a.push_back(small);
            return;
        }
        for(int k=i;k<s.length();k++){
            if(checkpalindrome(s,i,k)){
                small.push_back(s.substr(i,k-i+1));
                findUtil(s,a,k+1,small);
                small.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> a;
        if(s.length()==0){
            return a;
        }
        vector<string> small;
        findUtil(s,a,0,small);
        return a;
    }
};
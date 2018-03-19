/*

392. Is Subsequence

Given a string s and a string t, check if s is subsequence of t.

You may assume that there is only lower case English letters in both s and t. t is potentially a very long (length ~= 500,000) string, and s is a short string (<=100).

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ace" is a subsequence of "abcde" while "aec" is not).

Example 1:
s = "abc", t = "ahbgdc"

Return true.

Example 2:
s = "axc", t = "ahbgdc"

Return false.

Follow up:
If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and you want to check one by one to see if T has its subsequence. In this scenario, how would you change your code?
*/

class Solution {
public:
    bool check(string s,string t,int i,int j){
        if(i>=s.length()){
            return true;
        }
        for(int  k=j;k<t.length();k++){
            if(s[i]==t[k]){
                i=i+1;
                k=k+1;
                if(check(s,t,i,k)){
                    return true;
                }
                i=i-1;
                k=k-1;
            }
        }
        return false;
    }
    bool isSubsequence(string s, string t) {
        if(s.length()==0 && t.length()==0){
            return true;
        }
        if(s.length()>t.length()){
            return false;
        }
        return check(s,t,0,0);
    }
};
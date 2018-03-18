/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.
 

Example:

Input: "cbbd"

Output: "bb"
*/
class Solution {
public:
    bool palindrome(string s){
        int i=0;
        int j=s.length()-1;
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        string a;
        if(s.length()==0){
            return a;
        }
        if(palindrome(s)){
            return s;
        }
        a=s[0];
        for(int j=s.length();j>0;j--){
            for(int i=0;i<j;i++){
                string c = s.substr(i,j-i+1);
                if(a.length()>=c.length()){
                    break;
                }
                if(palindrome(c) && a.length()<c.length()){
                    a=c;
                    break;
                }
            }
        }
        return a;
    }
};
/*
409. Longest Palindrome

Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.
*/
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        if(s.length()==0){
            return 0;
        }
        for(char c:s){
            mp[c]++;
        }
        int ans=0;
        int exist=0;
        for(pair<char,int> p:mp){
            int k = p.second;
            if(k%2==0){
                ans+=k;
            }else{
                ans+=k-1;
                exist=1;
            }
        }
        return ans+exist;
    }
};
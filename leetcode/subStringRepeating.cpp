/*
395. Longest Substring with At Least K Repeating Characters

Find the length of the longest substring T of a given string (consists of lowercase letters only) such that every character in T appears no less than k times.

Example 1:

Input:
s = "aaabb", k = 3

Output:
3

The longest substring is "aaa", as 'a' is repeated 3 times.
Example 2:

Input:
s = "ababbc", k = 2

Output:
5

The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.



*/

class Solution {
public:
    int ans=INT_MIN;
    int longestSubstring(string s, int k) {
        if(s.length()==0){
            return 0;
        }
        unordered_map<char,int> mp;
        for(char i : s){
            mp[i]++;
        }
        int i=0;
        while(i<s.length() && mp[s[i]]>=k){
            i++;
        }   
        if(i==s.length()){
            return s.length();
        }
        string left = s.substr(0,i);
        string right = s.substr(i+1,s.length());
        int m = longestSubstring(left,k);
        int p = longestSubstring(right,k);
        ans=max(ans,max(m,p));
        return ans;
    }
};
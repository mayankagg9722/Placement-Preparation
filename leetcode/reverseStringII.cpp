/*
541. Reverse String II

Given a string and an integer k, you need to reverse the first k characters for every 2k characters counting from the start of the string. If there are less than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and left the other as original.
Example:
Input: s = "abcdefg", k = 2
Output: "bacdfeg"
Restrictions:
The string consists of lower English letters only.
Length of the given string and k will in the range [1, 10000]
*/

class Solution {
public:
   void reverseUtil(string &s,int i,int k){
        if(i+k>s.length()){
            reverse(s.begin()+i,s.end());
            return;
        }
        reverse(s.begin()+i,s.begin()+i+k);
        reverseUtil(s,i+2*k,k);
    }
    string reverseStr(string s, int k) {
        reverseUtil(s,0,k);
        return s;
    }
};
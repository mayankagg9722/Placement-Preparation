/*
58. Length of Last Word

Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.
*/
class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.length()==0){
            return 0;
        }
        int i=s.length()-1;
        int c=0;
        while(s[i]==' ' && i>=0){
            i--;
        }
        while(s[i]!=' ' && i>=0){
            c++;
            i--;
        }
        return c;
    }
};
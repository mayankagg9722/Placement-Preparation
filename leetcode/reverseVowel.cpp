/*

345. Reverse Vowels of a String

Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Given s = "hello", return "holle".

Example 2:
Given s = "leetcode", return "leotcede".

Note:
The vowels does not include the letter "y".
*/
class Solution {
public:
    bool vowel(char i){
        if(i=='a' || i=='e' || i=='i' || i=='o' || i=='u' || i=='A' || i=='E' || i=='I' || i=='O' || i=='U'){
            return true;
        }
        return false;
    }
    string reverseVowels(string s) {
        int i=0;int j=s.length()-1;
        while(i<j){
            if(!vowel(s[i])){
                i++;
            }
            if(!vowel(s[j])){
                j--;
            }
            if(vowel(s[i]) && vowel(s[j])){
                char t=s[i];
                s[i]=s[j];
                s[j]=t;
                i++;
                j--;
            }
        }
        return s;
    }
};
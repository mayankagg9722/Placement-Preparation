/*
459. Repeated Substring Pattern

Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.
Example 1:
Input: "abab"

Output: True

Explanation: It's the substring "ab" twice.
*/
class Solution {
public:
    bool check(string sub,int length,string s){
        int i=0;
        while(i<s.length()){
            if(s.substr(i,length)!=sub){
                return false;
            }
            i=i+length;
        }
       return true; 
    }
    bool repeatedSubstringPattern(string s) {
        if(s.length()<=1){
            return false;
        }
        int j=1;
        vector<int> index;
        while(j<s.length()){
            if(s[0]==s[j]){
                index.push_back(j);
            }
            j++;
        }
        vector<string> substring;
        for(int i=0;i<index.size();i++){
            string sub = s.substr(0,index[i]);
            if(check(sub,sub.length(),s)){
                return true;
            }
        }
        return false;
    }
};
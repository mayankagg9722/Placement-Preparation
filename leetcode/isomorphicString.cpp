/*
205. Isomorphic Strings

Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length()){
            return false;
        }
        unordered_map<char,char> mmap;
        unordered_map<char,char> :: iterator it;
        for(int i=0;i<s.length();i++){
            if(mmap.find(s[i])!=mmap.end()){
                if(mmap.find(s[i])->second!=t[i]){
                    return false;
                }
            }else{
                int f=0;
                for(it=mmap.begin();it!=mmap.end();it++){
                    if(it->second==t[i]){
                        f=1;
                        return false;
                    }
                }
                if(f==0){
                    mmap[s[i]]=t[i];
                }
            }
        }
        return true;
    }
};
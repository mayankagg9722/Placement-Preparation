/*
242. Valid Anagram

Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        cout<<s.length();
        if(s.length()==0 && t.length()==0){
            return true;
        }
        if(s.length()!=t.length()){
            return false;
        }
        unordered_map<char,int> mp;
        for(char i : s){
            mp[i]++;
        }
        for(char i : t){
            if(mp.count(i)){
                mp[i]--;
            }else{
                return false;
            }
        }
        for(pair<char,int> p : mp){
            if(p.second!=0){
                return false;
            }
        }
        return true;
    }
};
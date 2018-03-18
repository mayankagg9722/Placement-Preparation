/*
383. Ransom Note
Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true
*/
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> mp;
        for(char s:magazine){
            mp[s]++;
        }
        for(char s:ransomNote){
            if(mp.find(s)!=mp.end() && mp[s]>0){
                mp[s]--;
            }else{
                return false;    
            }
        }
        return true;
    }
};
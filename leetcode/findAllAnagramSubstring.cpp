/*
438. Find All Anagrams in a String

Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".

class Solution {
public:
    unordered_map<char,int> :: iterator t;
    bool check(unordered_map<char,int> mp){
        for(t=mp.begin();t!=mp.end();t++){
            if(t->second!=0){
                return false;
            }
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if(s.length()==0 || s.length()<p.length()){
            return ans;
        }
        unordered_map<char,int> nmp;
        unordered_map<char,int> :: iterator it;
        for(char c : p){
            nmp[c]++;
        }
        for(int i=0;i<s.length()-p.length()+1;i++){
            unordered_map<char,int> mp=nmp;
            int k=i;
            t = mp.find(s[k]);
            while(t!=mp.end() && t->second>0){
                t->second-=1;
                k++;
                if(k>=s.length()){
                    break;
                }
                t=mp.find(s[k]);
            }
            if(check(mp)){
                ans.push_back(i);
            }
        }
        return ans;
        
    }
};
*/

class Solution {
public:
    unordered_map<char,int> :: iterator t;
    bool check(unordered_map<char,int> mp){
        for(t=mp.begin();t!=mp.end();t++){
            if(t->second!=0){
                return false;
            }
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if(s.length()<p.length()){
            return ans;
        }
        unordered_map<char,int> mp;
        for(char c : p){
            mp[c]++;
        }
        int i=0;
        int rem = p.length();
        for(int j=0;j<s.length();j++){
            if(mp.find(s[j])==mp.end()){
                while(i<j){
                    mp[s[i]]++;
                    rem++;
                    i++;
                }
                i=j+1;
                continue;
            }
            if(mp[s[j]]<=0){
                while(mp[s[j]]<=0){
                    mp[s[i]]++;
                    i++;
                    rem++;
                }
            }
            if(mp[s[j]]>0){
                mp[s[j]]--;
                rem--;
            }
            if(rem==0){
                ans.push_back(j-p.length()+1);
            }
        }
        return ans;
        
    }
};
/*
451. Sort Characters By Frequency

Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
*/
class Solution {
public:
    string frequencySort(string s) {
        string a="";
        unordered_map<char,int> mp;
        unordered_map<char,int> :: iterator it;
        vector<string> finalv (s.length()+1,"");
        for(char t:s){
            mp[t]++;
        }
        
        for(it=mp.begin();it!=mp.end();it++){
            char c = it->first;
            int n = it->second;
            finalv[n].append(n,c);
        }
    
        for(int i=s.length();i>=0;i--){
            if(finalv[i].length()>0){
                a.append(finalv[i]);
            }
        }
        return a;
    }
};
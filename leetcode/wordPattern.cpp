/*
290. Word Pattern

Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.
*/
class Solution {
public:
    vector<string> split(string str){
        int k=0;
        string s="";
        vector<string> lt;
        while(k!=str.length()){
            if(str[k]==' '){
                lt.push_back(s);
                s="";
                k++;
            }
            s+=str[k++];
        }
        lt.push_back(s);
        return lt;
    }
    bool wordPattern(string pt, string str) {
        vector<string> lt;
        lt=split(str);
        if(lt.size()!=pt.length()){
            return false;
        }
        unordered_map<char,string> mp;
        unordered_map<char,string> :: iterator it;
        for(int i=0;i<pt.length();i++){
            for(it=mp.begin();it!=mp.end();it++){
                if(it->second==lt[i] && it->first!=pt[i]){
                    return false;
                }
                if(it->first==pt[i] && it->second!=lt[i]){
                    return false;
                }
            }
            mp[pt[i]]=lt[i];
        }
        return true;
    }
};
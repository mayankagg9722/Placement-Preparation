/*
500. Keyboard Row
Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below.


American keyboard


Example 1:
Input: ["Hello", "Alaska", "Dad", "Peace"]
Output: ["Alaska", "Dad"]
*/
class Solution {
public:
    int finds(char c){
        string s="qwertyuiop";
        string s1="asdfghjkl";
        string s2="zxcvbnm";
        cout<<c<<endl;
        if(s.find(c)!=string::npos){
            return 0;
        }
        if(s1.find(c)!=string::npos){
            return 1;
        }
        if(s2.find(c)!=string::npos){
            return 2;
        }
        return -1;
    }
    vector<string> findWords(vector<string>& words) {
        vector<string> ans;
        for(string s: words ){
            int k=finds(s[0]);
            int f=0;
            for(char c: s){
                if(k!=finds(c)){
                    f=-1;
                    break;
                }
            }
            if(f==0){
                ans.push_back(s);
            }
        }
        return ans;
    }
};
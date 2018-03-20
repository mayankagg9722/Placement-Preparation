/*
434. Number of Segments in a String

Count the number of segments in a string, where a segment is defined to be a contiguous sequence of non-space characters.

Please note that the string does not contain any non-printable characters.

Example:

Input: "Hello, my name is John"
Output: 5
*/
class Solution {
public:
    void move(string s,int &i){
        while(s[i]==' '){
            i++;
        }
    }
    int countSegments(string s) {
        int i=0;
        int ans=0;
        move(s,i);
        string p="";
        while(i<s.length()){
            if(s[i]==' '){
                p="";
                ans+=1;
                move(s,i);
            }else{
                p+=s[i];
                i++;
            }
        }
        if(p.length()>0){
            ans+=1;
        }
        return ans;
    }
};
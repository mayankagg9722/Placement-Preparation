/*
402. Remove K Digits

Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

Note:
The length of num is less than 10002 and will be ≥ k.
The given num does not contain any leading zero.
Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
*/
class Solution {
public:
    string remove(string s){
        int i=0;
        while(i<s.length() && s[i]=='0'){
            i++;
        }
        s.erase(s.begin()+0,s.begin()+i);
        return s;
    }
    string removeKdigits(string s, int k) {
        int i=0;
        s=remove(s);
        if(k>=s.length()){
            return "0";
        }
        while(k!=0){
            if(i==s.length()-1){
                break;
            }
            s=remove(s);
            int fir = s[i]-'0';
            int sec = s[i+1]-'0';
            if(fir==sec || fir<sec){
                i++;
            }else{
                s.erase(s.begin()+i,s.begin()+i+1);
                k--;
                i--;
            }
        }
        s=remove(s);
        if(k>0){
            s.erase(s.end()-k,s.end());
        }
        if(s.length()==0){
            s="0";
        }
        return s;
    }
};
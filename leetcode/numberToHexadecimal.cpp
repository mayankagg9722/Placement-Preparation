/*
405. Convert a Number to Hexadecimal

Given an integer, write an algorithm to convert it to hexadecimal. For negative integer, two’s complement method is used.

Note:

All letters in hexadecimal (a-f) must be in lowercase.
The hexadecimal string must not contain extra leading 0s. If the number is zero, it is represented by a single zero character '0'; otherwise, the first character in the hexadecimal string will not be the zero character.
The given number is guaranteed to fit within the range of a 32-bit signed integer.
You must not use any method provided by the library which converts/formats the number to hex directly.
Example 1:

Input:
26

Output:
"1a"
Example 2:

Input:
-1

Output:
"ffffffff"
*/
class Solution {
public:
    void remove(string &ans){
        int i=0;
        while(i<ans.length() && ans[i]=='0'){
            i++;
        }
        ans.erase(ans.begin()+0,ans.begin()+i);
    }
    char check(int i){
        if(i>=0 && i<=9){
            char c = i+'0';
            return c;
        }
        char c = 87+i;
        return c;
    }
    void binary(int i,vector<int>& a){
        while(i){
            int k = i%2;
            a.push_back(k);
            i=i/2;
        }
        while(a.size()!=32){
            a.push_back(0);
        }
        reverse(a.begin(),a.end());
    }
    void twoscomplement(vector<int>& a){
        int i;
        for(i=a.size()-1;i>=0;i--){
            if(a[i]==1){
                break;
            }
        }
        for(int k=0;k<i;k++){
            if(a[k]==0){
                a[k]=1;
            }else{
                a[k]=0;
            }
        }
    }
    string hexNumber(vector<int> a){
        string ans="";
        int c=0;
        int k=0;
        for(int i=a.size()-1;i>=0;i--){
            k=k+(a[i]*pow(2,c));
            c++;
            if(c==4){
                ans+=check(k);
                c=0;
                k=0;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    string toHex(int num) {
        if(num==0){
            return "0";
        }
        if(num>0){
            string ans="";
            vector<char> a;
            while(num){
                int r = num%16;
                a.push_back(check(r));
                num=num/16;
            }
            for(int i=a.size()-1;i>=0;i--){
                ans+=a[i];
            }
            remove(ans);
            if(ans.length()==0){
                return "0";
            }
            return ans;
        }else{
            if(num==INT_MIN){
                return "80000000";
            }
            vector<int> a;
            binary(-1*num,a);
            twoscomplement(a);
            string ans = hexNumber(a);
            remove(ans);
            if(ans.length()==0){
                return "0";
            }
            return ans;
        }
        return "0";
    }
};
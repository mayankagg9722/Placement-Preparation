// Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

// Note:

// The length of both num1 and num2 is < 5100.
// Both num1 and num2 contains only digits 0-9.
// Both num1 and num2 does not contain any leading zero.
// You must not use any built-in BigInteger library or convert the inputs to integer directly.
class Solution {
public:
    void add(char i, char j,string &num3,int &carry){
        int t=((int)(i)-'0')+((int)(j)-'0')+carry;
        carry=t/10;
        num3.append(to_string(t%10));
    }
    string addStrings(string num1, string num2) {
        string num3;
        int carry=0;
        if(num1.length()==num2.length()){
            for(int i=num2.length()-1;i>=0;i--){
                add(num2[i],num1[i],num3,carry);
            }
        }
        else if(num1.length()>num2.length()){
            int l=num1.length()-1;
            for(int i=num2.length()-1;i>=0;i--){
                add(num2[i],num1[l--],num3,carry);
            }
            for(int i=l;i>=0;i--){
                add(num1[i],'0',num3,carry);
            }
        }else{
            int l=num2.length()-1;
            for(int i=num1.length()-1;i>=0;i--){
                cout<<"w1"<<endl;
                add(num2[l--],num1[i],num3,carry);
            }
            for(int i=l;i>=0;i--){
                add(num2[i],'0',num3,carry);
            }
        }
        if(carry==1){
            num3.append(to_string(1));
        }
        reverse(num3.begin(), num3.end());
        return num3;
    }
};
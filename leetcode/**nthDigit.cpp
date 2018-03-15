/*
400. Nth Digit

Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...

Note:
n is positive and will fit within the range of a 32-bit signed integer (n < 231).

Example 1:

Input:
3

Output:
3
Example 2:

Input:
11

Output:
0

Explanation:
The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.
*/
class Solution {
public:
    int findNthDigit(int n) {
        // string s="";
        // int i=1;
        // while(s.length()<n){
        //     s+=to_string(i++);
        // }
        // return s[n-1]-'0';
        if(n<=9){
            return n;
        }
        int i=1;
        long int s=0;
        long int ten=1;
        int t;
        while(true){
            t=s;
            s+=i*(9*ten);
            ten=ten*10;
            if(s>n){
                break;
            }
            i++;
        }
        t=t+1;
        long int rem = (n-t)%i;
        long int no = ((n-t)/i)+pow(10,(i-1));
        string str = to_string(no);
        cout<<str;
        return str[rem]-'0';
    }
};
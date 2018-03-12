/*
258. Add Digits

Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

For example:

Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.

Follow up:
Could you do it without any loop/recursion in O(1) runtime?
*/
class Solution {
public:
    int count(int a){
        int c=0;
        while(a){
            c++;
            a=a/10;
        }
        return c;
    }
    int add(int a){
        int c=0;
        while(a){
            int k=a%10;
            c+=k;
            a=a/10;
        }
        return c;
    }
    int addDigits(int num) {
        while(num!=0 && count(num)!=1){
            num=add(num);
        }
        return num;
    }
};
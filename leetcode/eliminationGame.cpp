/*
390. Elimination Game

There is a list of sorted integers from 1 to n. Starting from left to right, remove the first number and every other number afterward until you reach the end of the list.

Repeat the previous step again, but this time from right to left, remove the right most number and every other number from the remaining numbers.

We keep repeating the steps again, alternating left to right and right to left, until a single number remains.

Find the last number that remains starting with a list of length n.

Example:

Input:
n = 9,
1 2 3 4 5 6 7 8 9
2 4 6 8
2 6
6

Output:
6
*/
class Solution {
public:
    int lastRemaining(int n) {
        if(n==1){
            return 1;
        }
        if(n==2){
            return 2;
        }
        int count=1;
        int x=2;
        int y=0;
        while(x*count+y<=n){
            count++;
        }
        count--;
        if(count==1){
            return x*count+y;
        }
        bool turn=true;
        while(1){
            if(turn){
                if(count%2==0){
                    y=y-x;
                    x=x*2;
                }else{
                    x=x*2;
                }
                turn=false;
            }else{
                x=x*2;
                turn=true;
            }
            count=1;
            while(x*count+y<=n){
                count++;
            }
            count--;
            if(count==1){
                return x*count+y;
            }
        }
        return 0;
    }
};
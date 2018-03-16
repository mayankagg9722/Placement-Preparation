/*
374. Guess Number Higher or Lower

We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I'll tell you whether the number is higher or lower.

You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, or 0):

-1 : My number is lower
 1 : My number is higher
 0 : Congrats! You got it!
Example:
n = 10, I pick 6.

Return 6.
*/
// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0

int guess(int num);

class Solution {
public:
    int f=0;
    void findin(int s,int e){
        if(f!=0){
            return;
        }
        int mid = s+((e-s)/2);
        int l = guess(mid);
        cout<<mid<<endl;
        if(l==0){
            f=mid;
            return;
        }else if(l==-1){
            findin(s,mid-1);
        }else{
            findin(mid+1,e);
        }
    }
    int guessNumber(int n) {
        findin(1,n);
        return f;
    }
};
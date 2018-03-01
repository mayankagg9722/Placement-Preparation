/*

172. Factorial Trailing Zeroes

Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.
*/
class Solution {
public:
    int trailingZeroes(int n) {
        int c2=0;
        int c5=0;
        long long int i=2;
        long long int j=5;
        while((n/i)>0){
            c2+=(n/i);
            i=i*2;
        }
        while((n/j)>0){
            cout<<n<<endl;
            cout<<j<<endl;
            c5+=(n/j);
            j=j*5;
        }
        cout<<c2<<endl;
        cout<<c5<<endl;
        int m = min(c2,c5);
        return m;
    }
};
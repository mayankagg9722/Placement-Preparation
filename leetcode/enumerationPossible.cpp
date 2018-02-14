//TLE
// class Solution {
// public:
//     int calc(int n){
//         int c=0;
//         if(n==0 ||n==1){
//             return 1;
//         }
//         if(n==2){
//             return 2;
//         }
//         for(int i=0;i<=n-1;i++){
//             c=c+calc(i)*calc(n-1-i);
//         }
//         return c;
//     }
//     int numTrees(int n) {
//         int s=calc(n);
//         return s;
//     }
// };

//or

// nth catalan no
unsigned long int catalan(unsigned int n)
{
    // Base case
    if (n <= 1) return 1;
 
    // catalan(n) is sum of catalan(i)*catalan(n-i-1)
    unsigned long int res = 0;
    for (int i=0; i<n; i++)
        res += catalan(i)*catalan(n-i-1);
 
    return res;
}


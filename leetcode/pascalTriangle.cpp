/*
118. Pascal's Triangle
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

class Solution {
public:
    // or (i-1)C(j) METHOD THROUGH COMBINATION BUT IT IS  OF VERY HIGH COMPLEXITY 
    /*long long int fact(int k){
        if(k==0){
            return 1;
        }
        return k*fact(k-1);
    }
    long long int combination(int i,int j){
        long long int p =  fact(i);
        long long int q =  fact(j);
        long long int r=  fact(i-j);
        return ((p/q)/r);
    }*/
    vector<vector<int>> generate(int nr) {
        vector<vector<int>> a;
        if(nr==0){
            return a;
        }else{
            vector<int> s;
            s.push_back(1);
            a.push_back(s);
            for(int i=1;i<=nr-1;i++){
                vector<int> small = a[a.size()-1];
                vector<int> mynew;
                mynew.push_back(1);
                for(int i=1;i<small.size();i++){
                    mynew.push_back(small[i-1]+small[i]);
                }
                mynew.push_back(1);
                a.push_back(mynew);
            }
        }

        // or (i-1)C(j) METHOD THROUGH COMBINATION BUT IT IS  OF VERY HIGH COMPLEXITY 
        // for(int i=0;i<nr;i++){
        //     vector<int> s;
        //     for(int j=0;j<=i;j++){
        //         s.push_back(combination(i,j));
        //     }
        //     a.push_back(s);
        // }
        return a;
    }
};
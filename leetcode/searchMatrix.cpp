/*

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
For example,

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.

Given target = 20, return false.
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int t) {
        int r=m.size();
        if(r==0){
            return false;
        }
        int c=m[0].size();
        if(c==0){
            return false;
        }
        for(int i=0;i<r;i++){
            if(m[i][0]>t){
                break;
            }
            for(int j=0;j<c;j++){
                if(m[i][0]>t){
                    break;
                }
                if(t==m[i][j]){
                    return true;
                }
            }
        }
        return false;
    }
};
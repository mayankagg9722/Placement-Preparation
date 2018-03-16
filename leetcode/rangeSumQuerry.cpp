/*
304. Range Sum Query 2D - Immutable

Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

Range Sum Query 2D
The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and (row2, col2) = (4, 3), which contains sum = 8.

Example:
Given matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]

sumRegion(2, 1, 4, 3) -> 8
sumRegion(1, 1, 2, 2) -> 11
sumRegion(1, 2, 2, 4) -> 12
Note:
You may assume that the matrix does not change.
There are many calls to sumRegion function.
You may assume that row1 ≤ row2 and col1 ≤ col2.
*/
class NumMatrix {
public:
    vector<vector<int>> a;
    NumMatrix(vector<vector<int>> matrix) {
        a=matrix;
        for(int p=0;p<a.size();p++){
            int s=0;
            for(int q=0;q<a[0].size();q++){
                s+=a[p][q];
                a[p][q]=s;
            }
        }
    }
    
    int sumRegion(int r1, int c1, int r2, int c2) {
        int k=0;
        int t=0;
        for(int q=r1;q<=r2;q++){
            if(c1!=0){
                k+=a[q][c1-1];
            }
        }
        for(int q=r1;q<=r2;q++){
                t+=a[q][c2];
        }
        return t-k;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
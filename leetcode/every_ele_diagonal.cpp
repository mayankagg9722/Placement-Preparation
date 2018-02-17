// A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same element.

// Now given an M x N matrix, return True if and only if the matrix is Toeplitz.
 

// Example 1:

// Input: matrix = [[1,2,3,4],[5,1,2,3],[9,5,1,2]]
// Output: True
// Explanation:
// 1234
// 5123
// 9512
// In the above grid, the diagonals are "[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]",
// and in each diagonal all elements are the same, so the answer is True.
class Solution {
public:
    bool findTrue(vector<vector<int>> a,int i,int j,int r,int c,int ele){
        if(i>=r || j>=c){
            return true;
        }
        if(a[i][j]!=ele){
            return false;
        }
        if(!findTrue(a,i+1,j+1,r,c,ele)){
            return false;
        }
        return true;
    }
    bool isToeplitzMatrix(vector<vector<int>>& a) {
        
        if(a.size()==0){
            return true;
        }
        int r=a.size();
        int c=a[0].size();
        for(int j=0;j<r;j++){
            if(!findTrue(a,j,0,r,c,a[j][0])){
                return false;
            }
        }
        for(int j=0;j<c;j++){
            if(!findTrue(a,0,j,r,c,a[0][j])){
                return false;
            }
        }
        return true;
    }
};
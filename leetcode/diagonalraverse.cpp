/*
498. Diagonal Traverse

Given a matrix of M x N elements (M rows, N columns), return all elements of the matrix in diagonal order as shown in the below image.

Example:
Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output:  [1,2,4,7,5,3,6,8,9]
Explanation:

Note:
The total number of elements of the given matrix will not exceed 10,000.
*/
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& m) {
        vector<int> ans;
        int i=0;
        int j=0;
        int r=m.size();
        if(r==0){
            return ans;
        }
        int c=m[0].size();
        vector<vector<int>> a(r+c-1,vector<int>());
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                a[i+j].push_back(m[i][j]);
            }
        }
        int k=0;
        for(vector<int> b:a){
            if(k!=0 && k%2==0){
                reverse(b.begin(),b.end());
            }
            for(int i:b){
                ans.push_back(i);
            }
            k++;
        }
        return ans;
    }
};
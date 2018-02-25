/*
120. Triangle

Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
*/
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int s=INT_MAX;
        for(int i=1;i<triangle.size();i++){
            vector<int> t = triangle[i-1];
            int size = triangle[i].size();
            triangle[i][0]=triangle[i][0]+t[0];
            triangle[i][size-1]=triangle[i][size-1]+t[size-2];
            for(int j=1;j<size-1;j++){
                triangle[i][j]=min(triangle[i][j]+t[j],triangle[i][j]+t[j-1]);
            }
        }
        for(int j=0;j<triangle[triangle.size()-1].size();j++){
            if(s>triangle[triangle.size()-1][j]){
                s=triangle[triangle.size()-1][j];
            }
        }
        return s;
    }
};
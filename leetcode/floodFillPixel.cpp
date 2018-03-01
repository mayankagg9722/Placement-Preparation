/*
An image is represented by a 2-D array of integers, each integer representing the pixel value of the image (from 0 to 65535).

Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.

At the end, return the modified image.

Example 1:
Input: 
image = [[1,1,1],[1,1,0],[1,0,1]]
sr = 1, sc = 1, newColor = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]

*/
class Solution {
public:
    int r,c;
    bool safe(int sr,int sc,vector<vector<int>> im,int prev){
        if(sr>=0 && sc>=0 && sr<r && sc<c){
            if(im[sr][sc]==prev){
                return true;    
            }
        }
        return false;
    }
    void floodUtil(vector<vector<int>>& im, int sr, int sc, int nc,int prev){
        if(sr<0 || sc<0 || sr>=r || sc>=c){
            return;
        }
        if(safe(sr-1,sc,im,prev)){
            im[sr-1][sc]=nc;
            floodUtil(im,sr-1,sc,nc,prev);
        }
        if(safe(sr+1,sc,im,prev)){
            im[sr+1][sc]=nc;
            floodUtil(im,sr+1,sc,nc,prev);
        }
        if(safe(sr,sc-1,im,prev)){
            im[sr][sc-1]=nc;
            floodUtil(im,sr,sc-1,nc,prev);
        }
        if(safe(sr,sc+1,im,prev)){
            im[sr][sc+1]=nc;
            floodUtil(im,sr,sc+1,nc,prev);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        r=image.size();
        if(r==0){
            return image;
        }
        c=image[0].size();
        int prev=image[sr][sc];
        if(newColor==prev){
            return image;
        }
        image[sr][sc]=newColor;
        floodUtil(image,sr,sc,newColor,prev);
        return image;
    }
};
/*
223. Rectangle Area

Find the total area covered by two rectilinear rectangles in a 2D plane.

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

Rectangle Area
*/
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int first_triangle=(C-A)*(D-B);
        int second_triangle=(G-E)*(H-F);
        int overlap=0;
        int l=max(E,A);
        int r=min(G,C);
        int t=max(F,B);
        int b=min(D,H);
        if(l<r && t<b){
            overlap=(r-l)*(b-t);
        }
        return first_triangle+second_triangle-overlap;
    }
};
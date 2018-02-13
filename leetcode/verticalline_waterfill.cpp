class Solution {
public:
    int maxArea(vector<int>& height) {
        int j=height.size()-1;
        int i=0;
        int max=-1;
        while(i<j){
            int h = min(height[i],height[j]);
            int area = h*(j-i);
            if(max<area){
                max=area;
            }
            if(height[i]<height[j]){
                i++;
            }else{
                j--;
            }
        }
        return max;
    }
};
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int max=-1;
        while(i<=j){
            if(height[i]<=height[j]){
                int v = height[i]*(j-i);
                if(max<v){
                    max=v;
                }
                i++;
            }else{
                int v = height[j]*(j-i);
                if(max<v){
                    max=v;
                }
                j--;
            }
        }
        return max;
    }
};
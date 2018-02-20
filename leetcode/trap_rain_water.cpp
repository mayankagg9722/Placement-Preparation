class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> maxfromleft;
        vector<int> maxfromright;
        int s = height.size();
        int max = -1;
        for(int i=0;i<s;i++){
            if(max<height[i]){
                max=height[i];
            }
            maxfromleft.push_back(max);
        }
        max=-1;
        for(int i=s-1;i>=0;i--){
            if(max<height[i]){
                max=height[i];
            }
            maxfromright.push_back(max);
        }
        reverse(maxfromright.begin(),maxfromright.end());
        // for(int i=0;i<s;i++){
        //     cout<<maxfromleft[i]<<" ";
        // }
        // cout<<endl;
        // for(int i=0;i<s;i++){
        //     cout<<maxfromright[i]<<" ";
        // }
        int store=0;
        for(int i=0;i<s;i++){
            if(height[i]!=maxfromright[i] || height[i]!=maxfromleft[i]){
                store=store+min(maxfromright[i],maxfromleft[i])-height[i];
            }
        }
        return store;
    }
};
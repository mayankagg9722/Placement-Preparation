class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int totalSize=nums1.size()+nums2.size();
        double median;
        int index1=totalSize/2;
        int index2=index1-1;
        int i=0;
        int j=0;
        int count=0;
        int flag=0;
        int n=0;
        int n1=-1;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]<nums2[j]){
                n=nums1[i];
                i++;
                count+=1;
            }else if(nums2[j]<nums1[i]){
                n=nums2[j];
                j++;
                count+=1;
            }else{
                n=nums1[i];
                i++;
                count+=1;
            }
            if(count==index2+1){
                n1=n;
            }
            if(count==index1+1){
                if(totalSize%2!=0){
                    median=(double)(n);
                    return median;
                }else{
                    median=(double)((n1+n)/2.0);
                    return median;
                }
                flag=1;
                break;
            }
        }
        if(flag==0){
            if(i!=nums1.size()){
                if(totalSize%2!=0){
                    median=(double)(nums1[i+index1-count]);
                    return median;
                }else{
                    if(n1==-1){
                        median=(double)((nums1[i+index1-count]+nums1[i+index1-count-1])/2.0);
                        return median;
                    }else{
                        median=(double)((nums1[i+index1-count]+n1)/2.0);
                        return median;
                    }
                }
                
            }else if(j!=nums2.size()){
                if(totalSize%2!=0){
                    median=(double)(nums2[j+index1-count]);
                    return median;
                }else{
                    if(n1==-1){
                        median=(double)((nums2[j+index1-count]+nums2[j+index1-count-1])/2.0);
                        return median;
                    }else{
                        median=(double)((nums2[j+index1-count]+n1)/2.0);
                        return median;
                    }
                }
            }
        }
        return median;
    }
};
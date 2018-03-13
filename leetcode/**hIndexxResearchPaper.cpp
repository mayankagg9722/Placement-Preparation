/*
274. H-Index

Given an array of citations (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.

According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each."

For example, given citations = [3, 0, 6, 1, 5], which means the researcher has 5 papers in total and each of them had received 3, 0, 6, 1, 5 citations respectively. Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, his h-index is 3.

Note: If there are several possible values for h, the maximum one is taken as the h-index.
*/

/*

//if sorted 


class Solution {
public:
    int hIndex(vector<int>& cit) {
        int c=0;
        int l=cit.size();
        for(int i=0;i<l;i++){
            if(cit[i]>=l-i){
                return l-i;
            }
        }
        return 0;
    }
};

*/

class Solution {
public:
    int hIndex(vector<int>& cit) {
        int n = cit.size();
        if(n==0){
            return 0;
        }
        vector<int> arr(n+1,0);
        for(int i:cit){
            if(i>n){
                arr[n]++;
            }else{
                arr[i]++;
            }
        }
        int tot=0;
        for(int i=n;i>=0;i--){
            tot+=arr[i];
            if(i<=tot){
                return i;
            }
        }
        return 0;
    }
};


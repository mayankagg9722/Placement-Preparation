/*
228. Summary Ranges

Given a sorted integer array without duplicates, return the summary of its ranges.

Example 1:
Input: [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Example 2:
Input: [0,2,3,4,6,8,9]
*/
class Solution {
public:
    vector<string> summaryRanges(vector<int>& n) {
        vector<string> s;
        if(n.size()==0){
            return s;
        }
        int i=0;
        int j=0;
        while(i<n.size()){
            int k=n[i];
            string a=to_string(k);
            j=i+1;
            while(j<n.size()){
                if(n[j]==k+1){
                    k=n[j];
                    j++;
                }else{
                    break;
                }
            }
            if(j-1!=i){
                a=a+"->"+to_string(n[j-1]);
            }
            s.push_back(a);
            i=j;
        }
        return s;
    }
};
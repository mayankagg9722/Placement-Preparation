/*
278. First Bad Version
DescriptionHintsSubmissionsDiscussSolution
You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which will return whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.

*/
// Forward declaration of isBadVersion API.

//remember if the numbers are too large the to find mid dont add up the two nos 
//just do s+(e-s)/2 and then find mid also avoid recussion in such cases.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int s=1;
        int e=n;
        while(s<e){
            int m = s+(e-s)/2;
            if(isBadVersion(m)){
                e=m;
            }else{
                s=m+1;
            }
        }
        return s;
    }
};
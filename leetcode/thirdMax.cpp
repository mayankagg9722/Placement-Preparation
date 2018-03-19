/*
414. Third Maximum Number

Given a non-empty array of integers, return the third maximum number in this array. If it does not exist, return the maximum number. The time complexity must be in O(n).

Example 1:
Input: [3, 2, 1]

Output: 1

Explanation: The third maximum is 1.
Example 2:
Input: [1, 2]

Output: 2

Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
Example 3:
Input: [2, 2, 3, 1]

Output: 1

Explanation: Note that the third maximum here means the third maximum distinct number.
Both numbers with value 2 are both considered as second maximum.
*/
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int a = INT_MIN;
        int b = INT_MIN;
        int c = INT_MIN;
        bool e = false;
        for(int i:nums){
            if(a<=i){
                a=i;
            }
        }
        for(int i:nums){
            if(b<=i && i<a){
                b=i;
            }
        }
        for(int i:nums){
            if(c<=i && i<b){
                e=true;
                c=i;
            }
        }
        cout<<a<<" "<<b<<" "<<c;
        if(e){
            return c;
        }
        return a;
    }
};
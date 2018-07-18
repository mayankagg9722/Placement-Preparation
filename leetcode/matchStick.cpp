/*
473. Matchsticks to Square

Remember the story of Little Match Girl? By now, you know exactly what matchsticks the little match girl has, please find out a way you can make one square by using up all those matchsticks. You should not break any stick, but you can link them up, and each matchstick must be used exactly one time.

Your input will be several matchsticks the girl has, represented with their stick length. Your output will either be true or false, to represent whether you could make one square using all the matchsticks the little match girl has.

Example 1:
Input: [1,1,2,2,2]
Output: true

Explanation: You can form a square with length 2, one side of the square came two sticks with length 1.
Example 2:
Input: [3,3,3,3,4]
Output: false

Explanation: You cannot find a way to form a square with all the matchsticks.
Note:
The length sum of the given matchsticks is in the range of 0 to 10^9.
The length of the given matchstick array will not exceed 15.
*/
class Solution {
public:
    bool util(vector<int> n,int side,vector<int> sum,int index){
        if(index>=n.size()){
            if(sum[0]==side && sum[1]==side && sum[2]==side && sum[3]==side){
                return true;
            }
            return false;
        }
        for(int i=0;i<4;i++){
            if(sum[i]+n[index]>side){
                continue;
            }
            sum[i]+=n[index];
            if(util(n,side,sum,index+1)){
                return true;
            }
            sum[i]-=n[index];
        }
        return false;
    }
    bool makesquare(vector<int> n) {
        if(n.size()<4){
            return false;
        }
        int s=0;
        sort(n.begin(),n.end());
        for(int i:n){
            s+=i;
        }
        if(s%4!=0){
            return false;
        }
        int side = s/4;
        if(n.back()>side){
            return false;
        }
        reverse(n.begin(),n.end());
        vector<int> sum(4,0);
        return util(n,side,sum,0);
    }
};
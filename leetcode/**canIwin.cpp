/*
464. Can I Win

In the "100 game," two players take turns adding, to a running total, any integer from 1..10. The player who first causes the running total to reach or exceed 100 wins.

What if we change the game so that players cannot re-use integers?

For example, two players might take turns drawing from a common pool of numbers of 1..15 without replacement until they reach a total >= 100.

Given an integer maxChoosableInteger and another integer desiredTotal, determine if the first player to move can force a win, assuming both players play optimally.

You can always assume that maxChoosableInteger will not be larger than 20 and desiredTotal will not be larger than 300.

Example

Input:
maxChoosableInteger = 10
desiredTotal = 11

Output:
false

Explanation:
No matter which integer the first player choose, the first player will lose.
The first player can choose an integer from 1 up to 10.
If the first player choose 1, the second player can only choose integers from 2 up to 10.
The second player will win by choosing 10 and get a total = 11, which is >= desiredTotal.
Same with other integers chosen by the first player, the second player will always win.
*/
class Solution {
public:
    vector<bool> used;
    unordered_map<int,bool> mp;
    int format(vector<bool> used){
        int n=0;
        for(int i:used){
            n = n << 1;
            if(i){
                n|=i;
            }
        }
        return n;
    }
    bool util(int dt){
        if(dt<=0){
            return false;
        }
        int key = format(used);
        if(mp.find(key)==mp.end()){
            int index=0;
            for(bool i : used){
                if(!i){
                    used[index]=true;
                    if(!util(dt-index+1)){
                        mp[key]=true;
                        used[index]=false;
                        return true;
                    }
                    used[index]=false;
                }
                index++;
            }
            mp[key]=false;
        }
        return mp.find(key)->second;
    }
    
    bool canIWin(int mi, int dt) {
        int s = (mi*(mi+1))/2;
        if(s<dt){
            return 0;
        }
        if(dt<=0){
            return 0;
        }
        for(int i=0;i<mi;i++){
            used.push_back(false);
        }
        return util(dt);
    }
    
};
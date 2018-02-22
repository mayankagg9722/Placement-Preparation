/*
174. Dungeon Game
The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially positioned in the top-left room and must fight his way through the dungeon to rescue the princess.

The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.
*/

class Solution {
public:
    int sethealth(int i){
        if(i<=0){
            return 1;
        }
        return i;
    }
    int calculateMinimumHP(vector<vector<int>>& g) {
        int m=g.size();
        int n=g[0].size();
        int dp[m][n];
        dp[m-1][n-1]=sethealth(1-g[m-1][n-1]);
        for(int i=m-2;i>=0;i--){
            dp[i][n-1]=sethealth(dp[i+1][n-1]-g[i][n-1]);
        }
        for(int i=n-2;i>=0;i--){
            dp[m-1][i]=sethealth(dp[m-1][i+1]-g[m-1][i]);
        }
        for(int i=m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                dp[i][j]=sethealth(min(dp[i+1][j],dp[i][j+1])-g[i][j]);
            }
        }
        return dp[0][0];
    }
};
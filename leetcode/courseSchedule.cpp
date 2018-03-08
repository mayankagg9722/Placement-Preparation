/*
207. Course Schedule

There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.

2, [[1,0],[0,1]]
*/
class Solution {
public:
    vector<bool> v;
    bool waitingPush(int i,vector<pair<int, int>>& preq,vector<int> wait){
        if(v[i]==true){
            return true;
        }
        wait.push_back(i);
        for(pair<int,int> p : preq){
            if(p.first==i){
                if(find(wait.begin(),wait.begin()+wait.size(),p.second)!=wait.end()){
                    return false;
                }
                if(!waitingPush(p.second,preq,wait)){
                    return false;
                }
            }
        }
        return true;
    }
    bool canFinish(int n, vector<pair<int, int>>& preq) {
        for(int i=0;i<n;i++){
            v.push_back(false);
        }
        for(int i=0;i<n;i++){
            vector<int> wait;
            if(!waitingPush(i,preq,wait)){
                return false;
            }
            v[i]=true;
        }
        return true;
    }
};
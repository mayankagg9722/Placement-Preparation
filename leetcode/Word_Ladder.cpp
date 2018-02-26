/*
127. Word Ladder
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log","cog"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.

*/

class Solution {
public:

    int res=0;
    bool found=false;
    int finalsum=INT_MAX;
    
    string compare(vector<string> mylist,string ew){
        int myres=INT_MIN;
        string finalstring;
        for(string s: mylist){
            int c=0;
            for(int i=0;i<ew.length();i++){
                if(s[i]==ew[i]){
                    c++;
                }
            }
            if(myres<c){
                myres=c;
                finalstring=s;
            }
        }
        return finalstring;
    }
    vector<string> findwords(string bw,int i,vector<string> wl,vector<bool> visited){
        vector<string> ar;
        for(int j=0;j<wl.size();j++){
            if(( bw.substr(0,i)==wl[j].substr(0,i)) && (bw.substr(i+1,bw.length())==wl[j].substr(i+1,bw.length())) &&     
                visited[j]==false){
                ar.push_back(wl[j]);
            }
        }
        return ar;
    }
    void makeTrue(string bw,vector<string> wl,vector<bool> &visited,bool f){
        for(int j=0;j<wl.size();j++){
            if(wl[j]==bw){
                visited[j]=f;
                break;
            }
        }
    }
    vector<int> getIndex(string bw,string ew){
        vector<int> index;
        for(int j=0;j<bw.length();j++){
            if(bw[j]!=ew[j]){
                index.push_back(j);
            }
        }
        return index;
    }
    void ladderutil(string bw, string ew, vector<string> wl,vector<bool> &visited){
        if(bw==ew){
            found=true;
            finalsum=min(finalsum,res); 
            return;
        }
        res=res+1;
        makeTrue(bw,wl,visited,true);
        vector<int> index=getIndex(bw,ew);
        for(int i: index){
            vector<string> mylist=findwords(bw,i,wl,visited);
            string newstring=compare(mylist,ew);
            ladderutil(newstring,ew,wl,visited);
        }
        res=res-1;
        makeTrue(bw,wl,visited,false);
    }
    
    int ladderLength(string bw, string ew, vector<string>& wl){
        vector<bool> visited (wl.size(),false);
        ladderutil(bw,ew,wl,visited);
        if(!found){
            return 0;
        }
        return finalsum+1;
    }
};
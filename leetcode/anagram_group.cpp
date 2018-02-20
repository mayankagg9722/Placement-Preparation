// class Solution {
// public:
    
//     // bool myComp(const vector<string> &lhs, const vector<string> &rhs) { return lhs.size() < rhs.size(); }
    
//     void swap(string &s,int i,int j){
//         char t=s[i];
//         s[i]=s[j];
//         s[j]=t;
//     }
//     void findAnagram(string s,int i,int j,vector<bool> &visited,vector<string> &t,vector<string> strs,int start){
//         if(i==j){
//             for(int p=start;p<strs.size();p++){
//                 if(strs[p]==s && visited[p]==false){
//                     t.push_back(strs[p]);
//                     visited[p]=true;
//                 }
//             }
//             return;
//         }
//         for(int k=i;k<=j;k++){
//             swap(s,k,i);
//             findAnagram(s,i+1,j,visited,t,strs,start);
//             swap(s,k,i);
//         }
//     }
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         vector<vector<string>> s;
//         vector<bool> visited;
//         for(int i=0;i<strs.size();i++){
//             visited.push_back(false);
//         }
        
//         // for null length string
//         int f=0;
//         vector<string> t;
//         for(int i=0;i<strs.size();i++){
//             if(visited[i]==false && strs[i].length()==0){
//                 f=1;
//                 visited[i]=true;
//                 t.push_back(strs[i]);
//             }
//         }
//         if(f==1){
//             s.push_back(t);
//         }
//         for(int i=0;i<strs.size();i++){
//             if(visited[i]==false){
//                 vector<string> t;
//                 t.push_back(strs[i]);
//                 visited[i]=true;
//                 findAnagram(strs[i],0,strs[i].length()-1,visited,t,strs,i);
//                 sort(t.begin(),t.end());
//                 s.push_back(t);
//             }
//         }
//         sort(s.begin(),s.end(),[](const vector<string> &lhs, const vector<string> &rhs) { return lhs.size() < rhs.size(); });
//         return s;
//     }
};





//or




class Solution {
public:
    
    struct myhash{
        string key;
        vector<string> val;
    };
    string alphabet(string s){
        sort(s.begin(),s.end());
        return s;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> s;
        vector<myhash> hasharray;
        for(int i=0;i<strs.size();i++){
            int q=0;
            for(int k=0;k<hasharray.size();k++){
                if(hasharray[k].key==alphabet(strs[i])){
                    q=1;
                    hasharray[k].val.push_back(strs[i]);
                    break;
                }
            }
            if(q==0){
                struct myhash newhash;
                newhash.key=alphabet(strs[i]);
                newhash.val.push_back(strs[i]);
                hasharray.push_back(newhash);
            }
        }
        for(int k=0;k<hasharray.size();k++){
            sort(hasharray[k].val.begin(),hasharray[k].val.end());
            s.push_back(hasharray[k].val);
        }
        sort(s.begin(),s.end(),[](const vector<string> &lhs, const vector<string> &rhs) { return lhs.size() < rhs.size();});
        return s;
    }
};
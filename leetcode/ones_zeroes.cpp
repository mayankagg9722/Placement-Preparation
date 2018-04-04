struct compare {
    bool operator()(const std::string& first, const std::string& second) {
        return first.size() < second.size();
    }
};
class Solution {
public:
    int ans = INT_MIN;
    int countOne(string s){
        int o=0;
        int j=0;
        while(j<s.length()){
            if(s[j]=='1'){
                o++;
            }
            j++;
        }
        return o;
    }
    void util(vector<string>& strs , int z,int o,vector<bool> &vs,int t){
        if(z<0 || o<0){
            ans=max(ans,t-1);
            return;
        }
        ans=max(ans,t);
        for(int i=0;i<strs.size();i++){
            if(vs[i]==false){
                int ones = countOne(strs[i]);
                int zeroes = strs[i].length()-ones;
                o=o-ones;
                z=z-zeroes;
                vs[i]=true;
                util(strs,z,o,vs,t+1);
                vs[i]=false;
                o=o+ones;
                z=z+zeroes;
            }
        }
    }
    int findMaxForm(vector<string>& strs, int z, int o) {
            vector<bool> vs(strs.size(),false);
            util(strs,z,o,vs,0);
        return ans;
    }
};
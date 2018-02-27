class Solution {
public:
    bool findRemove(string &s, vector<string>& wd){
        if(s.length()==0){
            return true;
        }
        for(int i=0;i<wd.size();i++){
            string fs = wd[i];
            size_t k = s.find(fs);
            if(k==0){
                s.erase(s.begin(),s.begin()+fs.length());
                if(findRemove(s,wd)){
                    return true;
                }
                s.insert(0,fs);
            }
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wd) {
        if(s.length()==0){
            return true;
        }
        return findRemove(s,wd);
    }
};



/*
OR


class Solution {
public:
    bool findDict(string s, vector<string>& wd){
        for( string st : wd){
            if(s==st){
                return true;
            }
        }
        return false;
    }
    bool findRemove(string s, vector<string>& wd){
        int size=s.length();
        if(size==0){
            return true;
        }
        for(int i=0;i<=size;i++){
            string prev=s.substr(0,i);
            string next=s.substr(i,size-i);
            if(findDict(prev,wd) && findRemove(next,wd)){
                return true;
            }
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wd) {
        if(s.length()==0){
            return true;
        }
        return findRemove(s,wd);
    }
};


*/
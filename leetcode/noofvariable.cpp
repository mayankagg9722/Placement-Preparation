#include<iostream>
#include<string>
#include<set>
using namespace std;
int main(){
    unsigned int n;
    cin>>n;
    cin.ignore();
    set<string> myset;
    while(n--){
        string s;
        getline(cin,s);
        int pos;
        for(unsigned int i=0;i<s.length();i++){
            if(s[i]=='='){
                pos=i;
                break;
            }
        }
        string l="";
        for(unsigned int k=0;k<pos;k++){
            l+=s[k];
        }
        myset.insert(l);
    }
    cout<<myset.size();
    return 0;
}
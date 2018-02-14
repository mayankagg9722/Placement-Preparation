#include<iostream>
using namespace std;
int numDecodings(string s,int n) {
    if(n==0 || n==1){
        return 1;
    }
    int count=0;
    if(s[n-1]>'0'){
        count=numDecodings(s,n-1);
    }
    if((s[n-2]=='1' || s[n-2]=='2') && s[n-1]<'7'){
        count=count+numDecodings(s,n-2);
    }
    return count;
}

int main(){
    if(s.length()==0){
            return 0;
        }
        if(s[0]=='0'){
            return 0;
        }
    int count=numDecodings("1234",4);
    cout<<count<<endl;
    return 0;
}

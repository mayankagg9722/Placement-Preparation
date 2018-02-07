#include <iostream>
using namespace std;
int m=1;

void myfunct(int n){
    if(n==2){
        m=m*2;
        return;
    }
    if(n==3){
        m=m*3;
        return;
    }
    if(n%2==0){
        myfunct(n/2);
        myfunct(n/2);
    }else{
        myfunct((n-1)/2);
        myfunct((n+1)/2);
    }
}

int main()
{
    myfunct(23);
    cout << "Maximum Product is " << m<<"\n";
    return 0;
}
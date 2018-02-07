#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
int a=INT_MAX,b=INT_MAX,c=INT_MAX;
int reachn(int n){
	

	if(n==1){
		return 0;
	}else if(n%2==0){
		a=1+reachn(n/2);
	}else if(n%3==0){
		b=1+reachn(n/3);
	}else{
		c=1+reachn(n-1);
	}

	return min(a,min(b,c));
}
int main()
{
	int n;
	cin>>n;
	int k=reachn(n);
	cout<<"answer:"<<k;
	return 0;
}
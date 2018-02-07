#include<iostream>
using namespace std;

int n;
void findJumps(int a[n],int jumps,int start){
	if(start+a[start]>=n-1){
		jumps=jumps+1; 
		cout<<jumps;
		return;
	}
	int max=-1;
	int k=a[start];
	int chosen;
	for(int p=start+1;p<=start+k;p++){
		if(max<(p+a[p])){
			max=p+a[p];
			chosen=p;
		}
	}
	jumps=jumps+1; 
	findJumps(a,jumps,chosen);
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;

	while(t--){
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		findJumps(a,0,0);
	}	
	return 0;
}


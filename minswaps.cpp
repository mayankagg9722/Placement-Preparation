#include<iostream>
#include<limits>
using namespace std;
#define n 5
// int findMin(int a[n],int k){
// 	int min=INT_MAX;
// 	int minIndex=-1;
// 	for(int i=k;i<n;i++){
// 		if(min>a[i]){
// 			min=a[i];
// 			minIndex=i;
// 		}
// 	}
// 	return minIndex;
// }

void findMinMax(int a[n],int i,int j,int &p,int &q){
	int min=INT_MAX;
	int max=INT_MIN;
	for(int t=i;t<=j;t++){
		if(min>a[t]){
			min=a[t];
			p=t;
		}
		if(max<a[t]){
			max=a[t];
			q=t;
		}
	}
}

void findSwaps(int a[n],int sw,int i,int j){
	if(i>j){
		cout<<"Swaps: "<<sw<<"\n";
		// for(int k=0;k<n;k++){
		// 	cout<<a[k]<<" ";
		// }
		return;
	}
	int p=-1,q=-1;
	findMinMax(a,i,j,p,q);
	// cout<<"i:"<<i<<"j:"<<j<<"\n";
	// cout<<"p:"<<p<<"q:"<<q<<"\n";
	if(i==p && j==q){
		findSwaps(a,sw,i+1,j-1);
	}else{
		if(i==q && j==p){
			int t=a[i];
			a[i]=a[j];
			a[j]=t;
			sw+=1;
		}else if(i==p && j!=q){
			int g=a[j];
			a[j]=a[q];
			a[q]=g;
			sw+=1;
		}else if(i!=p && j==q){
			int t=a[i];
			a[i]=a[p];
			a[p]=t;
			sw+=1;
		}else if(i!=p && j!=q){
			int t=a[i];
			a[i]=a[p];
			a[p]=t;

			int g=a[j];
			a[j]=a[q];
			a[q]=g;
			sw+=2;
		}
		findSwaps(a,sw,i+1,j-1);
	}
	

	// for (int i=0;i<n;i++){
	// 	int minIndex=findMin(a,i);
	// 	if(i!=minIndex){
	// 		sw++;
	// 		int t=a[i];
	// 		a[i]=a[minIndex];
	// 		a[minIndex]=t;
	// 	}
	// }
	// cout<<"Swaps: "<<sw<<"\n";
}

int main()
{
	int a[n]={2, 5, 4, 3, 1};
	int sw=0;
	findSwaps(a,sw,0,n-1);
	return 0;
}

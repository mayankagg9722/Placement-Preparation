#include<iostream>
using namespace std;

void printArray(int a[8]){
	for(int i=0;i<8;i++){
		cout<<a[i]<<" ";
	}
	cout<<"\n";
}

int pivotSorting(int a[8],int low,int high){
	int pivotElement=a[high];
	int i=low-1;
	for(int j=low;j<high;j++){
		if(a[j]<pivotElement){
			i=i+1;
			int t=a[i];
			a[i]=a[j];
			a[j]=t;
		}
	}
	int t=a[high];
	a[high]=a[i+1];
	a[i+1]=t;
	// printArray(a);
	return (i+1);
}

void quickSort(int a[8],int start,int end){
	if(start<end){
		int p=pivotSorting(a,start,end);
		quickSort(a,start,p-1);
		quickSort(a,p,end);
	}
}

int main(){
	int a[8]={9,7,6,15,16,5,10,11};
	quickSort(a,0,7);
	printArray(a);
	return 0;
}

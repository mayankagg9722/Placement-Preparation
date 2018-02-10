#include<iostream>
using namespace std;

void insertionSort(int a[8]){
	for(int i=0;i<8;i++){
		int k=a[i];
		int j=i-1;
		while(j>=0 && a[j]>k){
			a[j+1]=a[j];
			j=j-1;
		}
		a[j+1]=k;
	}
}

int main()
{
	int a[8]={9,7,6,15,16,5,10,11};
	insertionSort(a);
	for(int i=0;i<8;i++){
		cout<<a[i]<<"\t";
	}
	return 0;
}

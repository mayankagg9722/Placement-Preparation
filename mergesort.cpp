#include<iostream>
using namespace std;

void printArray(int a[8]){
	for(int i=0;i<8;i++){
		cout<<a[i]<<" ";
	}
	cout<<"\n";
}

void merge(int a[8],int low,int middle,int high){
	
	int n1=middle-low+1;
	int n2=high-middle;
	int l[n1];
	int r[n2];
	int i,j,k;

	for (i=0; i<n1; i++)
		l[i] = a[low + i];

    for (j=0; j<n2; j++)
    	r[j] = a[middle + 1+ j];

    i=0;
    j=0;
    k=low;

    while(i<n1 && j<n2){
    	if(l[i]<=r[j]){
    		a[k]=l[i];
    		i++;
    	}else{
    		a[k]=r[j];
    		j++;
    	}
    	k++;
    }

    while(i<n1){
    	a[k]=l[i];
		i++;
		k++;
    }

    while(j<n2){
    	a[k]=r[j];
		j++;
		k++;
    }
 
}

void mergeSort(int a[8],int start,int end){
	if(start<end){
		int m=start+((end-start)/2);
		mergeSort(a,start,m);
		mergeSort(a,m+1,end);
		merge(a,start,m,end);
	}
}

int main(){
	int a[8]={9,7,6,15,16,5,10,11};
	mergeSort(a,0,7);
	printArray(a);
	return 0;
}
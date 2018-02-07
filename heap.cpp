#include<stdio.h>
#define heapSize 7
int a[heapSize];
int parent(int i){
	return i/2;
}

int left(int i){
	return (2*i);
}

int right(int i){
	return ((2*i)+1);
}

int leaf(int l){
	return l/2;
}

void printArray(int size){
	for(int i=1;i<=size;i++){
		printf("%d\t",a[i]);
	}
	printf("\n");
}

void maxHeapify(int i,int size){
	int l=left(i);
	int r=right(i);
	int largest;
	if(l<=size && a[l] > a[i]){
		largest=l;
	}else{
		largest=i;
	}

	if(r<=size && a[r] > a[largest]){
		largest=r;
	}

	if(largest!=i){
		int t=a[largest];
		a[largest]=a[i];
		a[i]=t;
		maxHeapify(largest,size);
	}

}

void buildMaxHeap(int s){
	for(int i=leaf(s);i>=1;i--){
		maxHeapify(i,s);
	}
}

void heapSort(int size){
	while(size>=1){
		printf("%d\t",a[1]);
		a[1]=a[size];
		size=size-1;
		buildMaxHeap(size);
	}
}

int main()
{
	for(int i=1;i<=heapSize;i++){
		a[i]=i;
	}
	printf("My Array:\n");
	printArray(heapSize);
	printf("My Sorted Array:\n");
	buildMaxHeap(heapSize);
	heapSort(heapSize);
	printf("\n");
	return 0;
}
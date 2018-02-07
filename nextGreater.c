#include<stdio.h>

int main()
{
	int n=6;
	int a[6]={1,5,3,2,4,6};
	int b[n],c[n];
	

	for(int i=0;i<n;i++){
		b[i]=-1;
		c[i]=-1;
	}

	int k=0;
	for(int i=0;i<n;i++){
		while( k>0 && (a[i]>a[c[k-1]] )){
			b[c[k-1]]=a[i];
			k=k-1;
		}
		c[k]=i;
		k=k+1;
	}

	for(int i=0;i<n;i++){
		printf("%d\n",b[i]);
	}

	return 0;
}
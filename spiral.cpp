#include<stdio.h>
#define n 5
int a[n][n];
void spiralMatrix(int a[n][n],int p,int q,int s){
	if(s==0){
		return;
	}
	int j=0;
	int i=0;
	for (j = q; j < s; j++){
		printf("%d\t", a[p][j]);
	}
	j=j-1;
	printf("\n");

	for(i=p+1;i<s;i++){
		printf("%d\t", a[i][j]);
	}
	i=i-1;
	printf("\n");

	for(j=j-1;j>=q;j--){
		printf("%d\t", a[i][j]);
	}
	j=j+1;
	printf("\n");

	for(i=i-1;i>p;i--){
		printf("%d\t", a[i][j]);
	}
	printf("\n");

	spiralMatrix(a,i+1,j+1,s-1);

}
void printArray(int a[n][n]){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	
	int k=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			a[i][j]=k;
			k++;
		}
	}
	printArray(a);
	printf("\n");
	spiralMatrix(a,0,0,5);
	return 0;
}
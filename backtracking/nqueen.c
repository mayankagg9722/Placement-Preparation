#include<stdio.h>
#define n 8
int a[n][n];
int safe(int i,int j){
	
	int count=0;

	for(int p=j-1;p>=0;p--){
		if(a[i][p]==1){
			count=1;
			break;
		}
	}
	if(count==1){
		return 0;
	}

	int p=i-1;
	int q=j-1;
	count=0;
	while(p>=0 && q>=0){
		if(a[p][q]==1){
			count=1;
			break;
		}
		p--;
		q--;
	}

	if(count==1){
		return 0;
	}

	p=i+1;
	q=j-1;
	count=0;
	while(p<n && q>=0){
		if(a[p][q]==1){
			count=1;
			break;
		}
		p++;
		q--;
	}

	if(count==1){
		return 0;
	}

	return 1;	
}

void printarray(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	printf("##############################\n");
}

void nqueen(int j){
	
	if(j>=n){
		printarray();
		return;
	}

	for(int i=0;i<n;i++){
		if(safe(i,j)){
			a[i][j]=1;
			nqueen(j+1);
			a[i][j]=0;
		}
	}
}
int main()
{
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			a[i][j]=0;
		}
	}
	nqueen(0);
	return 0;
}
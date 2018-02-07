#include<stdio.h>
#include<stdlib.h>

int a[3][3] = {{1,2, 9},{5, 3, 8},{4, 6, 7}};

void findMaxPath(int i,int j,int *k){
	
	
	if(i<0 || i>2 || j<0 || j>2){
		return;
	}

	printf("%d\n",a[i][j]);
	*k=*k+1;

	if(a[i+1][j]-a[i][j]==1 && i+1<3){
		findMaxPath(i+1,j,k);
	}

	if(a[i-1][j]-a[i][j]==1 && i-1>=0){
		findMaxPath(i-1,j,k);
	}

	if(a[i][j+1]-a[i][j]==1 && j+1<3){
		findMaxPath(i,j+1,k);
	}

	if(a[i][j-1]-a[i][j]==1 && j-1>=0){
		findMaxPath(i,j-1,k);
	}

}
int main()
{
	int max=-1;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			printf("\n");
			int k=0;
			findMaxPath(i,j,&k);
			printf("Path Length:%d\n",k);
			printf("\n");
			if(k>max){
				max=k;
			}
		}
	}
	printf("MAX:%d\n",max);
	return 0;
}
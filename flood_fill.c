#include <stdio.h>

int m,n;

void changeColor(int arr[m][n],int px,int py,int new,int old_color){

	if(px<0 || py<0 || px>m || py>n || arr[px][py]!=old_color){
		return;
	}

	else{
		arr[px][py]=new;
	}

	changeColor(arr,px+1,py,new,old_color);
	changeColor(arr,px-1,py,new,old_color);
	changeColor(arr,px,py+1,new,old_color);
	changeColor(arr,px,py-1,new,old_color);

}

int main()
{
	int px,py,new;
	int i,j;

	printf("Enter m:\n");
	scanf("%d",&m);
	printf("Enter n:\n");
	scanf("%d",&n);
	printf("Enter px:\n");
	scanf("%d",&px);
	printf("Enter py:\n");
	scanf("%d",&py);
	printf("Enter new:\n");
	scanf("%d",&new);

	printf("Enter nos:\n");

	int arr[m][n];
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&arr[i][j]);
		}
	}

	printf("OLD:\n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("%d",arr[i][j]);
		}

		printf("\n");
	}

	int old_color=arr[px][py];

	changeColor(arr,px,py,new,old_color);

	printf("new:\n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("%d",arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}
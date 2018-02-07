#include<stdio.h>
#define n 9


int safe(int a[n][n],int i,int j,int k){

	//row
	for(int p=0;p<n;p++){
		if(a[i][p]==k){
			return 0;
		}
	}

	//column
	for(int p=0;p<n;p++){
		if(a[p][j]==k){
			return 0;
		}
	}
	
	if(i>=0 && i<=2){
		if(j>=0 && j<=2){
			for(int p=0;p<=2;p++){
				for(int q=0;q<=2;q++){
					if(a[p][q]==k){
						return 0;
					}
				}
			}
		}else if(j>=3 && j<=5){
			for(int p=0;p<=2;p++){
				for(int q=3;q<=5;q++){
					if(a[p][q]==k){
						return 0;
					}
				}
			}
		}else if(j>=6 && j<=8){
			for(int p=0;p<=2;p++){
				for(int q=6;q<=8;q++){
					if(a[p][q]==k){
						return 0;
					}
				}
			}
		}
	}
	else if(i>=3 && i<=5){
		if(j>=0 && j<=2){
			for(int p=3;p<=5;p++){
				for(int q=0;q<=2;q++){
					if(a[p][q]==k){
						return 0;
					}
				}
			}
		}else if(j>=3 && j<=5){
			for(int p=3;p<=5;p++){
				for(int q=3;q<=5;q++){
					if(a[p][q]==k){
						return 0;
					}
				}
			}
		}else if(j>=6 && j<=8){
			for(int p=3;p<=5;p++){
				for(int q=6;q<=8;q++){
					if(a[p][q]==k){
						return 0;
					}
				}
			}
		}
	}else if(i>=6 && i<=8){
		if(j>=0 && j<=2){
			for(int p=6;p<=8;p++){
				for(int q=0;q<=2;q++){
					if(a[p][q]==k){
						return 0;
					}
				}
			}
		}else if(j>=3 && j<=5){
			for(int p=6;p<=8;p++){
				for(int q=3;q<=5;q++){
					if(a[p][q]==k){
						return 0;
					}
				}
			}
		}else if(j>=6 && j<=8){
			for(int p=6;p<=8;p++){
				for(int q=6;q<=8;q++){
					if(a[p][q]==k){
						return 0;
					}
				}
			}
		}
	}

	return 1;
}

void printarray(int a[n][n]){
	printf("##############################\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	printf("##############################\n");
}

int findIJ(int a[n][n],int *i,int *j){
	for(int p=0;p<n;p++){
		for(int q=0;q<n;q++){
			if(a[p][q]==0){
				*i=p;
				*j=q;
				return 1;
			}
		}
	}
	return 0;
}

void sudoku(int a[n][n]){

	int i=0;
	int j=0;

	if(!findIJ(a,&i,&j)){
		printarray(a);
		printf("\n");
		return;
	}

	for(int k=1;k<=9;k++){
		if(safe(a,i,j,k)){
			a[i][j]=k;
			sudoku(a);
			a[i][j]=0;
		}
	}

}
int main()
{
	// int t;
	// scanf("%d",&t);
	// while(t--){
	// 	int a[n][n];
	// 	for(int i=0;i<n;i++){
	// 		for(int j=0;j<n;j++){
	// 			// scanf("%d",&a[i][j]);
	// 			a[i][j]=0;
	// 		}
	// 	}
	// 	a[0][1]=3;
	// 	sudoku(a);
	// }
	int a[n][n]={
	{3,0,6,5,0,8,4,0,0},
	{5,2,0,0,0,0,0,0,0},
	{0,8,7,0,0,0,0,3,1},
	{0,0,3,0,1,0,0,8,0},
	{9,0,0,8,6,3,0,0,5},
	{0,5,0,0,9,0,6,0,0},
	{1,3,0,0,0,0,2,5,0},
	{0,0,0,0,0,0,0,7,4},
	{0,0,5,2,0,6,3,0,0}
	};
	// int a[n][n]={
	// {8,0,0,0,0,0,0,0,0},
	// {0,0,3,6,0,0,0,0,0},
	// {0,7,0,0,9,0,2,0,0},
	// {0,5,0,0,0,7,0,0,0},
	// {0,0,0,0,4,5,7,0,0},
	// {0,0,0,1,0,0,0,3,0},
	// {0,0,1,0,0,0,0,6,8},
	// {0,0,8,5,0,0,0,1,0},
	// {0,9,0,0,0,0,4,0,0}
	// };
	sudoku(a);
	return 0;
}
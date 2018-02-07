#include<stdio.h>

int safe(int i,int j,int a[8][8]){
	return(i>=0 && i<8 && j>=0 && j<8 && a[i][j]==-1);
}

void printChess(int a[8][8]){
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	printf("\n#################\n");
}

int solveKnightChessUtil(int i,int j,int t,int a[8][8],int x[8],int y[8]){
	int nexti,nextj,k;
	if(t==64){
		return 1;
	}
	for(k=0;k<8;k++){
		nexti=i+x[k];
		nextj=j+y[k];
		if(safe(nexti,nextj,a)){
			a[nexti][nextj]=t;
			if(solveKnightChessUtil(nexti,nextj,t+1,a,x,y)==1){
				return 1;
			}else{
				a[nexti][nextj]=-1;	
			}
			
		}
	}
	return 0;
}

void solveKnightChess(){
	int a[8][8];
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			a[i][j]=-1;
		}
	}
	// int x[8]={2,2,-2,-2,1,-1,1,-1};
	// int y[8]={1,-1,1,-1,2,2,-2,-2};


	int x[8] = {2,1,-1,-2,-2,-1,1,2};
    int y[8] = {1,2,2,1,-1,-2,-2,-1 };
	a[0][0]=0;
	if(solveKnightChessUtil(0,0,1,a,x,y)==0){
		printf("No Solution\n");
	}else{
		printChess(a);
	}
}

int main(){
	solveKnightChess();
	return 0;
}
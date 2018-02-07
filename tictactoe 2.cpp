#include<iostream>
#define n 3
using namespace std;
bool isMovesLeft(int a[3][3]){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[i][j]==-1){
				return true;
			}
		}
	}
	return false;
}
int evaluate(int a[3][3]){
	
	if(a[0][0]==a[1][1] && a[0][0]==a[2][2]){
		if(a[0][0]==0){
			return -10;
		}else if(a[0][0]==1){
			return 10;
		}
	}

	if(a[0][2]==a[1][1] && a[0][2]==a[2][0]){
		if(a[0][2]==0){
			return -10;
		}else if(a[0][0]==1){
			return 10;
		}
	}

	int k=a[0][0];
	int t=a[0][2];
	int ct=0;
	int count=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==j){
				if(k==a[i][j]){
					count++;
				}
			}
			if(i+j==2){
				if(t==a[i][j]){
					ct++;
				}
			}
		}
	}
	if(count==3 || ct==3){
		if(k==0){
			return -10;
		}else if(k==1){
			return 10;
		}
	}

	for(int i=0;i<n;i++){
		int k=a[i][0];
		int count=0;
		for(int j=0;j<n;j++){
			if(k==a[i][j]){
				count=count+1;
			}
		}
		if(count==3){
			if(k==0){
				return -10;
			}else if(k==1){
				return 10;
			}
		}
	}

	for(int i=0;i<n;i++){
		int k=a[0][i];
		int count=0;
		for(int j=0;j<n;j++){
			if(k==a[j][i]){
				count=count+1;
			}
		}
		if(count==3){
			if(k==0){
				return -10;
			}else if(k==1){
				return 10;
			}
		}
	}
	return 0;
}

int minmax(int a[3][3],int depth,int isComp){
	int score=evaluate(a);
	if(score==-10){
		return score;
	}

	if(score==10){
		return score;
	}

	if(!isMovesLeft(a)){
		return 0;
	}

	if(isComp){
		int best=-1000;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(a[i][j]==-1){
					a[i][j]=1;
					best=max(minmax(a,depth+1,!isComp),best);
					a[i][j]=-1;
				}
			}
		}
		return best;
	}
	else{
		int best=1000;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(a[i][j]==-1){
					a[i][j]=0;
					best=min(minmax(a,depth+1,!isComp),best);
					a[i][j]=-1;
				}
			}
		}
		return best;
	}
}



void findBestMove(int a[3][3]){

	int best=-10000;
	int p=-1;
	int q=-1;

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[i][j]==-1){
				a[i][j]=1;
				int score=minmax(a,0,false);
				a[i][j]=-1;
				if(best<score){
					best=score;
					p=i;
					q=j;
				}
			}
		}
	}

	cout<<" BEST MOVE:\n"<<" i: "<<p<<" j: "<<q<<"\n";

}
int main()
{
	int a[3][3]={{1,0,1},{0,0,1},{-1,-1,0}};
	findBestMove(a);
	return 0;
}
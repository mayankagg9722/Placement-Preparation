#include<iostream>
using namespace std;
int n=3;
int m=4;
int a[3][4]={{1,0,0,0},
			 {1,1,0,1},
			 {0,1,1,1}};

bool visited[3][4];
int t=0;
bool isSafe(int i,int j){
	if(a[i][j]==1 && i>=0 && i<n && j>=0 && j<m && visited[i][j]==false){
		return true;
	}
	return false;
}

void isPath(int i,int j,int x,int y){
	if(i==x && j==y){
		cout<<"t:"<<t<<"\n";
		return;
	}
	t++;
	visited[i][j]=true;
	if(isSafe(i+1,j)){
		isPath(i+1,j,x,y);
	}

	if(isSafe(i-1,j)){
		isPath(i-1,j,x,y);
	}

	if(isSafe(i,j+1)){
		isPath(i,j+1,x,y);
	}

	if(isSafe(i,j-1)){
		isPath(i,j-1,x,y);
	}
	return;
}

int main()
{
	int x,y;
	x=2;
	y=3;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			visited[i][j]=false;
		}
	}
	isPath(0,0,x,y);
	return 0;
}

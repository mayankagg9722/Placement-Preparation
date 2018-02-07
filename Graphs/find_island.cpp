#include<iostream>
using namespace std;
#define n 5

bool isSafe(int i, int j,int (&visited)[n][n],int m[n][n]){

	if(i>=0 && j>=0 && i<5 && j<5 && visited[i][j]==false && m[i][j]==1){
		return true;
	}
	return false;
}

void findIslandUtil(int i,int j,int (&visited)[n][n],int m[n][n]){
	
	if(i<0 || j<0 || j>=5 || i>=5){
		return;
	}

	visited[i][j]=true;
	
	if(isSafe(i+1,j,visited,m)){
		findIslandUtil(i+1,j,visited,m);
	}

	if(isSafe(i-1,j,visited,m)){
		findIslandUtil(i-1,j,visited,m);
	}

	if(isSafe(i,j+1,visited,m)){
		findIslandUtil(i,j+1,visited,m);
	}

	if(isSafe(i,j-1,visited,m)){
		findIslandUtil(i,j-1,visited,m);
	}

//diagonal
	if(isSafe(i-1,j-1,visited,m)){
		findIslandUtil(i-1,j-1,visited,m);
	}

	if(isSafe(i-1,j+1,visited,m)){
		findIslandUtil(i-1,j+1,visited,m);
	}

	if(isSafe(i+1,j-1,visited,m)){
		findIslandUtil(i+1,j-1,visited,m);
	}

	if(isSafe(i+1,j+1,visited,m)){
		findIslandUtil(i,j+1,visited,m);
	}

}

void findIsland(int m[n][n]){
	int visited[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			visited[i][j]=false;
		}
	}
	int count=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(!visited[i][j] && m[i][j]==1){
				// cout<<"i:"<<i<<"j:"<<j<<"\n";
				count++;
				findIslandUtil(i,j,visited,m);
			}
		}
	}
	cout<<"Count:"<<count<<"\n";
}
int main()
{
	int mat[n][n] = {{1, 1, 0, 0, 0},
	                 {0, 1, 0, 0, 1},
	                 {1, 0, 0, 1, 1},
	                 {0, 0, 0, 0, 0},
	                 {1, 0, 1, 0, 1}};
    findIsland(mat);
	return 0;
}
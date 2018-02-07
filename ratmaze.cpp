#include<stdio.h>
#include<vector>
using namespace std;
#define n 4
vector<char> path;

void printvector(){
	for(int i=0;i<path.size();i++){
		printf("%c",path[i]);
	}
	printf("\n#################\n");
}

void ratmaze(int a[n][n],int i,int j,char dir){
	
	if(i<0 || j<0 || i>=n || j>=n){
		return;
	}

	if(i==j && i==n-1){
		printvector();
		return;
	}

	if(dir!='u' && a[i+1][j]==1 && i<n){
		path.push_back('D');
		ratmaze(a,i+1,j,'d');
		path.pop_back();
	}

	if(dir!='l' && a[i][j+1]==1 && j<n){
		path.push_back('R');
		ratmaze(a,i,j+1,'r');
		path.pop_back();
	}

	// if(dir!='d' && a[i-1][j]==1 && i>0){
	// 	path.push_back('U');
	// 	ratmaze(a,i-1,j,'u');
	// 	path.pop_back();
	// }

	// if(dir!='r' && a[i][j-1]==1 && j>0){
	// 	path.push_back('L');
	// 	ratmaze(a,i,j-1,'l');
	// 	path.pop_back();
	// }
}

int main()
{
	int a[n][n]={{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
	ratmaze(a,0,0,'d');
	return 0;
}
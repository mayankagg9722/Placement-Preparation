#include<iostream>
#include<vector>
#include<string>
using namespace std;
#define n 3

vector<vector<string> > possible;

void printword(string makewords,string dict[4]){

	for(int i=0;i<4;i++){
		if(makewords.compare(dict[i])==0){
			cout<<makewords<<"\n";
		}
	}
}

void wordBoggle(char a[n][n],string dict[4],string makewords,
	bool visited[n][n],int i,int j){
	
	visited[i][j]=true;
	makewords=makewords+a[i][j];
	printword(makewords,dict);
// #################
	if(j-1>=0 && visited[i][j-1]==false){
		wordBoggle(a,dict,makewords,visited,i,j-1);
	}

	if(j+1<3 && visited[i][j+1]==false){
		wordBoggle(a,dict,makewords,visited,i,j+1);
	}
// #################
	if(i-1>=0 && j-1>=0 && visited[i-1][j-1]==false){
		wordBoggle(a,dict,makewords,visited,i-1,j-1);
	}

	if(i-1>=0 && visited[i-1][j]==false){
		wordBoggle(a,dict,makewords,visited,i-1,j);
	}

	if(i-1>=0 && j+1<3 && visited[i-1][j+1]==false){
		wordBoggle(a,dict,makewords,visited,i-1,j+1);
	}
// #################
	if(i+1<3 && j-1>=0 && visited[i+1][j-1]==false){
		wordBoggle(a,dict,makewords,visited,i+1,j-1);
	}

	if(i+1<3 && visited[i+1][j]==false){
		wordBoggle(a,dict,makewords,visited,i+1,j);
	}

	if(i+1<3 && j+1<3 && visited[i+1][j+1]==false){
		wordBoggle(a,dict,makewords,visited,i+1,j+1);
	}

	if(makewords.length()>=1){
		makewords.erase(makewords.length()-1);
	}
	
	visited[i][j]=false;
// #################
}


int main()
{
	string dict[4]={"GEEKS", "FOR", "QUIZ", "GO"};
	// int m=3;
	// int n=3;
	char a[n][n]={{'G','I','Z'},
                 {'U','E','K'},
				 {'Q','S','E'}};
	bool visited[n][n] = {{false}};
	string makewords="";

	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			wordBoggle(a,dict,makewords,visited,i,j);
		}
	}
	
	return 0;
}
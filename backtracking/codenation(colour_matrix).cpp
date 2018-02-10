#include<iostream>
#include<limits>
using namespace std;
int n=2;
int a[3][2];
bool safe(int i,int j,int k){
	a[i][j]=k;
	for(int q=0;q<3;q++){
		int colour1=0;
		int colour2=0;
		int colour3=0;
		for(int p=0;p<n;p++){
			if(a[q][p]==1){
				colour1++;
			}else if(a[q][p]==2){
				colour2++;
			}else if(a[q][p]==3){
				colour3++;
			}
		}
		if(colour1==n || colour2==n || colour3==n){
			a[i][j]=-1;
			return false;
		}
	}

	for(int q=0;q<n;q++){
		int colour1=0;
		int colour2=0;
		int colour3=0;
		for(int p=0;p<3;p++){
			if(a[p][q]==1){
				colour1++;
			}else if(a[p][q]==2){
				colour2++;
			}else if(a[p][q]==3){
				colour3++;
			}
		}
		if(colour1==3 || colour2==3 || colour3==3){
			a[i][j]=-1;
			return false;
		}
	}
	
	return true;
}


int findIJ(int &i,int &j){
	for(int p=0;p<3;p++){
		for(int q=0;q<n;q++){
			if(a[p][q]==-1){
				i=p;
				j=q;
				return 1;
			}
		}
	}
	return 0;
}
void printMatrix(){
	for(int i=0;i<3;i++){
		for(int j=0;j<n;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"\n##########################\n";
}
void solveColour(unsigned long long &count){

	int i=0;
	int j=0;

	if(!findIJ(i,j)){
		count++;
		// printMatrix();
		// cout<<"c: "<<count<<"\n";
		return;
	}

	for(int k=1;k<=3;k++){
		if(safe(i,j,k)){
			a[i][j]=k;
			solveColour(count);
			a[i][j]=-1;
		}
	}
}

int main(int argc, char const *argv[])
{

	for(int i=0;i<3;i++){
		for(int j=0;j<n;j++){
			a[i][j]=-1;
		}
	}

	cout<<INT_MAX;

	unsigned long long count=0;
	solveColour(count);
	cout<<"Count:"<<count<<"\n";

	return 0;
}
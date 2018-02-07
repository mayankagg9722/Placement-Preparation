#include<iostream>
#include<list>
#include<limits>
using namespace std;

class Graph{
	int v;
	int m;
	list<int> *adj;

public:
	Graph(int v,int m){
		this->v=v;
		this->m=m;
		this->adj=new list<int>[v];
	}

	void addEdge(int src,int dest){
		(this->adj[src]).push_back(dest);
		//undirected
		(this->adj[dest]).push_back(src);
	}

	void isColourUtil(int i,int *colour){
		if(colour[i]==-1){
			list<int>:: iterator it;
			for(int k=1;k<=m;k++){
				int flag=0;
				for(it=adj[i].begin();it!=adj[i].end();it++){
					if(k==colour[*it]){
						flag=1;
						break;
					}
				}
				if(flag==0){
					colour[i]=k;
					break;
				}
			}
		}
	}

	void printColour(int *colour){
		for(int i=0;i<v;i++){
			cout<<colour[i]<<" ";
		}
		cout<<"\n";
	}

	bool isColouring(){
		int *colour=new int[v];
		for(int i=0;i<v;i++){
			colour[i]=-1;
		}
		for(int i=0;i<v;i++){
			isColourUtil(i,colour);
		}
		for(int i=0;i<v;i++){
			if(colour[i]==-1){
				return false;
			}
		}
		printColour(colour);
		return true;
	}



};
int main(){
	
	Graph g(4,3);
	g.addEdge(0,3);
	g.addEdge(3,2);
	g.addEdge(2,1);
	g.addEdge(0,1);
	g.addEdge(0,2);

	if(g.isColouring()){
		cout<<"YES IT CAN BE COLOURED\n";
	}else{
		cout<<"NO IT CAN'T BE COLOURED\n";
	}
	
	return 0;
}
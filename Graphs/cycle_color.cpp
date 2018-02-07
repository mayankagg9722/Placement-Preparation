#include<iostream>
#include<list>
#include<stack>
// #include <stdc++.h>
using namespace std;
enum Color {white,grey,black};
class Graph{
	int v;
	list<int> *adj;
public:
	Graph(int v){
		this->v=v;
		(this->adj)=new list<int>[v];
	}

	void addEdge(int u,int v){
		(this->adj)[u].push_back(v);
	}

	bool isCylcicUtil(int i,int *visited){

		visited[i]=grey;
		list<int>:: iterator k;
		for(k=this->adj[i].begin();k!=this->adj[i].end();k++){
			if(visited[*k]==grey){
				return true;
			}
			if(visited[*k]==white && isCylcicUtil(*k,visited)){
				return true;
			}
		}
		visited[i]=black;
		return false;
	}

	bool isCylic(){
		int *visited=new int[this->v];
		for(int i=0;i<v;i++){
			visited[i]=white;
		}
		for(int i=0;i<v;i++){
			if(visited[i]==white){
				if(isCylcicUtil(i,visited)){
					return true;
				}	
			}
		}
		return false;
	}
};
int main(){
	Graph g(4);
	g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 0);
    if(g.isCylic()){
    	cout<<"It is cylic"<<"\n";
    }else{
    	cout<<"It is not cylic"<<"\n";
    }
	return 0;
}
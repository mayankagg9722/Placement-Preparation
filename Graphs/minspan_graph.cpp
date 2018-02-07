#include<iostream>
#include<list>
#include<limits>
using namespace std;

class Graph{
	int v;
	list<int> *adj;
	list<int> *weight;

public:
	Graph(int v){
		this->v=v;
		this->adj=new list<int>[v];
		this->weight=new list<int>[v];
	}

	void addEdge(int src,int dest,int weight){
		(this->adj[src]).push_back(dest);
		(this->weight[src]).push_back(weight);
	}

	void minSpanTreeUtil(bool *visited,int *dist,int *parent){
		int min=INT_MAX;
		int pos;
		for(int j=0;j<this->v;j++){
			if(visited[j]==false && min>dist[j]){
				min=dist[j];
				pos=j;
			}
		}
		min=pos;
		visited[min]=true;
		for(int k=0;k<(this->adj[min]).size();k++){
			list<int>::iterator it = this->adj[min].begin();
			list<int>::iterator it2 = this->weight[min].begin();
			advance(it,k);
			advance(it2,k);
			int element=*it;
			int weight=*it2;
			if(visited[element]==false && dist[element]>weight){

				dist[element]=weight;
				parent[element]=min;
			}
		}
	}

	void printMST(int *dist,int *parent){
		for(int i=1;i<v;i++){
			cout<<"Edge: "<<parent[i]<<"-"<<i<<" Dist:"<<dist[i]<<"\n";
		}
	}

	void minSpanTree(){
		bool *visited = new bool[v];
		int *dist=new int[v];
		int *parent=new int[v];
		for(int i=0;i<v;i++){
			visited[i]=false;
			dist[i]=INT_MAX;
			parent[i]=-1;
		}
		dist[0]=0;
		parent[0]=-1;
		for(int i=0;i<v-1;i++){
			minSpanTreeUtil(visited,dist,parent);
		}
		printMST(dist,parent);
	}

};
int main(){
	Graph g(5);
	
	g.addEdge(0,1,2);
	g.addEdge(1,0,2);
	
	g.addEdge(1,2,3);
	g.addEdge(2,1,3);
	
	g.addEdge(0,3,6);
	g.addEdge(3,0,6);
	
	g.addEdge(3,1,8);
	g.addEdge(1,3,8);

	g.addEdge(3,4,9);
	g.addEdge(4,3,9);

	g.addEdge(2,4,7);
	g.addEdge(4,2,7);

	g.addEdge(1,4,5);
	g.addEdge(4,1,5);

	g.minSpanTree();

	return 0;
}
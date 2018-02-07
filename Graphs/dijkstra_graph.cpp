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

	void dijkstraUtil(bool *visited,int *dist,int *parent){
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
			if(visited[element]==false && dist[element]>dist[min]+weight){
				dist[element]=dist[min]+weight;
				parent[element]=min;
			}
		}
	}

	void printDIJ(int *dist,int *parent){
		for(int i=0;i<v;i++){
			cout<<i<<" Dist:"<<dist[i]<<"\n";
			// cout<<"Edge: "<<parent[i]<<"-"<<i<<" Dist:"<<dist[i]<<"\n";
		}
	}

	void dijkstra(){
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
			dijkstraUtil(visited,dist,parent);
		}
		printDIJ(dist,parent);
	}

};
int main(){
	Graph g(9);
	
	g.addEdge(0,1,4);
	g.addEdge(1,0,4);

	g.addEdge(0,7,8);
	g.addEdge(7,0,8);

	g.addEdge(7,1,11);
	g.addEdge(1,7,11);
	
	g.addEdge(1,2,8);
	g.addEdge(2,1,8);

	g.addEdge(7,8,7);
	g.addEdge(8,7,7);

	g.addEdge(7,6,1);
	g.addEdge(6,7,1);

	g.addEdge(2,8,2);
	g.addEdge(8,2,2);

	g.addEdge(8,6,6);
	g.addEdge(6,8,6);

	g.addEdge(6,5,2);
	g.addEdge(5,6,2);

	g.addEdge(5,2,4);
	g.addEdge(2,5,4);

	g.addEdge(2,3,7);
	g.addEdge(3,2,7);

	g.addEdge(5,3,14);
	g.addEdge(3,5,14);
	
	g.addEdge(4,3,9);
	g.addEdge(3,4,9);

	g.addEdge(5,4,10);
	g.addEdge(4,5,10);
	
	g.dijkstra();

	return 0;
}
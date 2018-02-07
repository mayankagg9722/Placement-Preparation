#include<iostream>
using namespace std;
struct Edge{
	int src;
	int dest;
	int weight;
};
class Graph{
	int v;
	int e;
	struct Edge *edges;
	int *parent;
public:
	Graph(int v,int e){
		this->v=v;
		this->e=e;
		this->edges=new Edge[e];
		parent=new int[v];
	}
	void addEdge(int i,int src,int dest,int weight){
		(this->edges[i]).src=src;
		(this->edges[i]).dest=dest;
		(this->edges[i]).weight=weight;
	}
	void sortEdges(){
		for(int i=0;i<this->e;i++){
			for(int j=0;j<this->e;j++){
				if((this->edges[j]).weight>(this->edges[i]).weight){
					struct Edge t=this->edges[j];
					this->edges[j]=this->edges[i];
					this->edges[i]=t;
				}
			}
		}
	}
	void initialize(){
		for(int i=0;i<this->v;i++){
			this->parent[i]=-1;
		}
	}
	int findParent(int v){
		if(this->parent[v]==-1){
			return v;
		}
		return findParent(parent[v]);
	}
	void unionij(int i,int j){
		int x=findParent(i);
		int y=findParent(j);
		parent[x]=y;
	}
	bool isCycle(int src,int dest){
		int i=findParent(src);
		int j=findParent(dest);
		if(i==j){
			return true;
		}
		unionij(i,j);
		return false;
	}
	void kruskal(){
		initialize();
		for(int i=0;i<this->e;i++){
			cout<<"Edge: "<<this->edges[i].src<<"-"<<this->edges[i].dest<<" "<<this->edges[i].weight<<"\n";
		}
		cout<<"\n#####################################\n";
		for(int i=0;i<this->e;i++){
			if(!isCycle(this->edges[i].src,this->edges[i].dest)){
				cout<<"Edge: "<<this->edges[i].src<<"-"<<this->edges[i].dest<<" "<<this->edges[i].weight<<"\n";
			}
		}
	}
};

int main(){
	Graph g(9,14);
	g.addEdge(0,0,1,4);
	g.addEdge(1,0,7,8);
	g.addEdge(2,1,2,8);
	g.addEdge(3,1,7,11);
	g.addEdge(4,7,8,7);
	g.addEdge(5,7,6,1);
	g.addEdge(6,2,8,2);
	g.addEdge(7,8,6,6);
	g.addEdge(8,2,5,4);
	g.addEdge(9,2,3,7);
	g.addEdge(10,6,5,2);
	g.addEdge(11,3,5,14);
	g.addEdge(12,3,4,9);
	g.addEdge(13,5,4,10);
	g.sortEdges();
	g.kruskal();
	return 0;
}
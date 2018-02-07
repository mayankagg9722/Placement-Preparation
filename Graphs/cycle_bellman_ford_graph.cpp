#include<iostream>
#include<list>
#include<limits>
using namespace std;
struct Edge{
	int src;
	int dest;
	int dis;
};

class Graph{
	int v;
	int e;
	struct Edge * edge;
public:
	Graph(int v,int e){
		this->v=v;
		this->e=e;
		this->edge=new Edge[e];
	}
	void addEdge(int i,int src,int dest,int dis){
		((this->edge)[i]).src=src;
		((this->edge)[i]).dest=dest;
		((this->edge)[i]).dis=dis;
	}
	bool isNegativeCycle(){
		int *dist=new int[this->v];
		for(int i=0;i<this->v;i++){
			dist[i]=INT_MAX;
		}
		
		dist[0]=0;

		for(int i=0;i<(this->v)-1;i++){
			for(int j=0;j<this->e;j++){
				int src=this->edge[j].src;
				int dest=this->edge[j].dest;
				int weight=this->edge[j].dis;
				if(dist[src]>dist[dest]+weight){
					dist[src]=dist[dest]+weight;
				}
			}
		}

		int flag=0;
		for(int i=0;i<1;i++){
			for(int j=0;j<this->e;j++){
				int src=this->edge[j].src;
				int dest=this->edge[j].dest;
				int weight=this->edge[j].dis;
				if(dist[src]>dist[dest]+weight){
					int flag=1;
					dist[src]=dist[dest]+weight;
					break;
				}
			}
		}
		if(flag==1){
			return true;
		}
		return false;
	}
};

int main()
{
	Graph g(5,8);
	int t=0;
	g.addEdge(t++,0,1,-1);
	g.addEdge(t++,0,2,4);
	g.addEdge(t++,1,2,3);
	g.addEdge(t++,1,3,2);
	g.addEdge(t++,1,4,2);
	g.addEdge(t++,3,2,5);
	g.addEdge(t++,3,1,1);
	g.addEdge(t++,4,3,-3);
	if(g.isNegativeCycle()){
		cout<<"yes negative cycle exist"<<"\n";
	}else{
		cout<<"no negative cycle"<<"\n";
	}
	return 0;
}

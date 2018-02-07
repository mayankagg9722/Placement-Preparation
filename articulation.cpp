#include<iostream>
#include<list>
using namespace std;

class Graph{
	int v;
	list<int> *adj;
public:
	Graph(int v){
		this->v=v;
		this->adj=new list<int>[v];
	}
	void addEdge(int u,int w){
		this->adj[u].push_back(w);
		this->adj[w].push_back(u);
	}
	void articulationUtil(int v,bool *visited,int *parent,int *low,int *high,
		int & childcout,int root){
		static int t=0;
		low[v]=t;
		high[v]=t;
		visited[v]=true;
		list<int>::iterator it;
		for(it=this->adj[v].begin();it!=this->adj[v].end();it++){
			int u = *it;
			if(!visited[u]){
				if(v==root){
					childcout++;
				}
				parent[u]=v;
				t=t+1;
				articulationUtil(u,visited,parent,low,high,childcout,root);
				// low[v]=min(low[v],low[u]);
				if(v==root && childcout>=2){
					cout<<"ART: "<<v<<"\n";
				}
				if(parent[v]!=-1 && high[v]<=low[u]){
					cout<<"ART: "<<v<<"\n";
				}
			}else if(parent[v]!=u){
				low[v]=min(low[v],low[u]);
			}
		}
	}
	void articulation(){
		int root=3;
		int childcout=0;
		bool *visited=new bool[this->v];
		int *parent=new int[this->v];
		int *low=new int[this->v];
		int *high=new int[this->v];
		for(int i=0;i<this->v;i++){
			visited[i]=false;
			parent[i]=-1;
			low[i]=-1;
			high[i]=-1;
		}
		parent[root]=-1;
		articulationUtil(root,visited,parent,low,high,childcout,root);
	}
};

int main(){

	Graph g(8);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(3,4);
	g.addEdge(4,6);
	g.addEdge(5,6);
	g.addEdge(5,4);
	g.addEdge(5,7);
	g.articulation();

	return 0;
}
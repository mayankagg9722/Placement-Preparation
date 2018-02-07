#include<iostream>
#include<list>
using namespace std;

class Graph {
	int v;
	list<int> *adj;

public:
	void addEdge(int v,int w)
	{
		(this->adj)[v].push_back(w);
	}

	Graph(int v){
		this->v=v;
		this->adj=new list<int>[v];
	}
	void bfs(int v){
		bool *visited=new bool[this->v];
		list<int> queue;
		list<int>::iterator i;
		list<int>::iterator j;

		for(int i=0;i<this->v;i++){
			visited[i]=false;
		}
	
		visited[v]=true;
		queue.push_back(v);
		j=queue.begin();

		while(j!=queue.end()){
			for(i=(this->adj)[*j].begin();i!=(this->adj)[*j].end();i++){
				if(visited[(*i)]==false){
					visited[*i]=true;
					queue.push_back(*i);	
				}
			}
			j++;
		}

		for(j=queue.begin();j!=queue.end();j++){
			cout<<*j<<"\n";
		}
	}
};

int main(){
	Graph g(4);
	g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.bfs(0);
	return 0;
}
#include<iostream>
#include<stack>
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

	void topologicalUtil(int v,bool *visited,stack<int> &st){
		visited[v]=true;
		list<int>::iterator i;
		for(i=(this->adj)[v].begin();i!=(this->adj)[v].end();i++){
			if(!visited[(*i)]){
				topologicalUtil(*i,visited,st);
			}
		}
		st.push(v);
	}

	void topological(){
		
		bool *visited=new bool[this->v];
		stack<int> st;

		for(int i=0;i<this->v;i++){
			visited[i]=false;
		}
	
		for(int i=0;i<this->v;i++){
			if(!visited[i]){
				topologicalUtil(i,visited,st);
			}
		}
		
		while(st.size()>0){
			cout<<st.top()<<"\n";
			st.pop();
		}
	}
};

int main(){
	Graph g(6);
	g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.topological();
	return 0;
}
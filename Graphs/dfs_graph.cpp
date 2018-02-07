#include<iostream>
#include<list>
#include<stack>
// #include <stdc++.h>
using namespace std;
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
	void dfs(int v){
		bool *visited=new bool[this->v];
		for(int i=0;i<this->v;i++){
			visited[i]=false;
		}
		stack<int> s;
		s.push(v);
		visited[v]=true;
		while(s.size()!=0){
			int i=s.top();
			cout<<i<<"\n";
			s.pop();
			visited[i]=true;
			list<int>:: iterator k;
			for(k=this->adj[i].begin();k!=this->adj[i].end();k++){
				if(!visited[*k]){
					s.push(*k);
				}
			}
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
    g.dfs(2);
	return 0;
}
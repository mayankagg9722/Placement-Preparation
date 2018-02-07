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

	bool isCylcicUtil(int i,bool *visited,bool *recstack){
		if(visited[i]==false){
			visited[i]=true;
			recstack[i]=true;
			list<int>:: iterator k;
			for(k=this->adj[i].begin();k!=this->adj[i].end();k++){
				if(!visited[*k] && isCylcicUtil(*k,visited,recstack)){
					return true;
				}else if(recstack[*k]){
					return true;
				}
			}
		}
		recstack[i]=false;
		return false;
	}

	bool isCylic(){
		bool *visited=new bool[this->v];
		bool *recstack=new bool[this->v];
		for(int i=0;i<v;i++){
			visited[i]=false;
			recstack[i]=false;
		}
		for(int i=0;i<v;i++){
			if(isCylcicUtil(i,visited,recstack)){
				return true;
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
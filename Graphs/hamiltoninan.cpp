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
		(this->adj)[w].push_back(v);
	}

	Graph(int v){
		this->v=v;
		this->adj=new list<int>[v];
	}

	void printStack(stack<int> st){
		cout<<"printing stack:\n";
		while(st.size()>0){
			cout<<st.top()<<"\n";
			st.pop();
		}
	}

	void hamiltonianUtil(int t,bool *visited,stack<int> &st,int start){
		visited[t]=true;
		st.push(t);
		list<int>::iterator i;
		for(i=(this->adj)[t].begin();i!=(this->adj)[t].end();i++){
			if(!visited[(*i)]){
				hamiltonianUtil(*i,visited,st,start);
				st.pop();
				visited[*i]=false;
			}else{
				if(st.size()==this->v){
					if(*i==start){
						printStack(st);
					}else{
						return;
					}	
				}
			}
		}
	}

	void hamiltonian(){
		bool *visited=new bool[this->v];
		stack<int> st;

		for(int i=0;i<this->v;i++){
			visited[i]=false;
		}
		int start=0;
		hamiltonianUtil(0,visited,st,start);
		// for(int i= 0;i<this->v;i++){
			
		// 	break;
		// }
	}
};

int main(){
	Graph g(5);
	g.addEdge(0, 1);
	g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(1, 4);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(4, 3);
    g.hamiltonian();
	return 0;
}
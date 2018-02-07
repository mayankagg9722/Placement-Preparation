#include<iostream>
#include<list>
#include<stack>
using namespace std;

class Graph{
	int v;
	list<int> *adj;
	list<int> *revadj;
public:	
	Graph(int v){
		this->v=v;
		this->adj=new list<int>[v];
		this->revadj=new list<int>[v];
	}
	void addEdge(int src,int dest){
		this->adj[src].push_back(dest);
		this->revadj[dest].push_back(src);
	}

	void printMainStack(stack<int> mainStack){
		while(mainStack.size()>0){
			int top=mainStack.top();
			cout<<top<<"\n";
			mainStack.pop();
		}
	}
	void doDFSkosarajuStep1(int v,stack<int> &mainStack,bool *visited){
		visited[v]=true;
		list<int>::iterator it;
		for(it=this->adj[v].begin();it!=this->adj[v].end();it++){
			if(!visited[*it]){
				doDFSkosarajuStep1(*it,mainStack,visited);	
			}
		}
		mainStack.push(v);
	}
	void doDFSkosarajuStep2(int v,bool *visited){
		cout<<v<<" ";
		visited[v]=true;
		list<int>::iterator it;
		for(it=this->revadj[v].begin();it!=this->revadj[v].end();it++){
			if(!visited[*it]){
				doDFSkosarajuStep2(*it,visited);	
			}
		}
	}
	void kosarajuStep2(stack<int> mainStack){
		bool *visited=new bool[this->v];
		for(int i=0;i<this->v;i++){
			visited[i]=false;
		}
		int t=1;
		while(mainStack.size()>0){
			int top=mainStack.top();
			if(!visited[top]){
				cout<<"\n"<<t++<<":"<<" ";
				doDFSkosarajuStep2(top,visited);
			}
			mainStack.pop();
		}
	}
	void kosarajuStep1(int start){
		bool *visited=new bool[this->v];
		stack<int> mainStack;
		for(int i=0;i<this->v;i++){
			visited[i]=false;
		}
		doDFSkosarajuStep1(start,mainStack,visited);
		for(int i=0;i<this->v;i++){
			if(!visited[i]){
				doDFSkosarajuStep1(i,mainStack,visited);
			}
		}
		cout<<"# MAIN STACK #\n";
		printMainStack(mainStack);
		cout<<"\n";
		cout<<"# SCC #\n";
		kosarajuStep2(mainStack);
		cout<<"\n";
	}

};
int main(int argc, char const *argv[])
{
	Graph g(11);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,0);
	g.addEdge(1,3);
	g.addEdge(3,4);
	g.addEdge(4,5);
	g.addEdge(5,3);
	g.addEdge(6,5);
	g.addEdge(6,7);
	g.addEdge(7,8);
	g.addEdge(8,9);
	g.addEdge(9,6);
	g.addEdge(9,10);
	g.kosarajuStep1(1);
	return 0;
}

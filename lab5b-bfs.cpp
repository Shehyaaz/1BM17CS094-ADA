//this program traveses a graph using BFS

#include <iostream>
#include <queue> // STL queue
using namespace std;

queue<int> q;

void BFS(int k,int **adj,bool *visited, int n){
	cout<<k+1<<" ";
	visited[k] = true;
	q.push(k);
	while(!q.empty()){
		int curr = q.front();
		q.pop();
		for(int i =0; i<n;i++){
			if(adj[curr][i] && !visited[i]){
				q.push(i);
				visited[i] = true;
				cout<<i+1<<" ";
			}
		}
	}
}

int main(){
	int **adj, k, n;
	bool *visited;
	cout<<"Enter the number of nodes :\n";
	cin>>n;
	visited = new bool[n];
	adj = new int*[n];
	for(int i=0; i<n;i++)
		adj[i] = new int[n];
	cout<<"Enter Adjacency Matrix :\n";
	for(int i=0; i<n;i++)
		for(int j =0; j<n;j++)
			cin>>adj[i][j];
	cout<<"Enter the source vertex :";
	cin>>k;
	BFS(k-1,adj,visited,n);
	return 0;
}

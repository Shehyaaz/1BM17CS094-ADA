// lab 4 additional, cycle in a directed graph 
#include<iostream> 
#include <list> 
#include <limits.h> 
using namespace std; 

class Graph 
{ 
	int V; // No. of vertices 
	list<int> *adj; // Pointer to an array containing adjacency lists 
	bool isCyclicUtil(int v, bool *visited, bool *rs); // used by isCyclic() 
public: 
	Graph(int V); // Constructor 
	void addEdge(int v, int w); // to add an edge to graph 
	bool isCyclic(); // returns true if there is a cycle in this graph 
}; 

Graph::Graph(int V) 
{ 
	this->V = V; 
	adj = new list<int>[V]; 
} 

void Graph::addEdge(int v, int w) 
{ 
	adj[v].push_back(w); // Add w to v’s list. 
} 

bool Graph::isCyclicUtil(int v, bool *visited, bool *recStack) 
{ 
	if(visited[v] == false) 
	{ 
		// Mark the current node as visited and part of recursion stack 
		visited[v] = true; 
		recStack[v] = true; 

		// Recur for all the vertices adjacent to this vertex 
		list<int>::iterator i; 
		for(i = adj[v].begin(); i != adj[v].end(); ++i) // auto i = adj[v].begin() can also be used
		{ 
			if ( !visited[*i] && isCyclicUtil(*i, visited, recStack) ) 
				return true; 
			else if (recStack[*i]) 
				return true; 
		} 

	} 
	recStack[v] = false; // remove the vertex from recursion stack 
	return false; 
} 

// Returns true if the graph contains a cycle, else false. 
bool Graph::isCyclic() 
{ 
	// Mark all the vertices as not visited and not part of recursion stack 
	bool *visited = new bool[V]; 
	bool *recStack = new bool[V]; 
	for(int i = 0; i < V; i++) 
	{ 
		visited[i] = false; 
		recStack[i] = false; 
	} 

	// Call the recursive helper function to detect cycle in different 
	// DFS trees 
	for(int i = 0; i < V; i++) 
		if (isCyclicUtil(i, visited, recStack)) 
			return true; 

	return false; 
} 

int main() 
{ 
	int n, adj_vertex = 0;
	cout<<"Enter number of vertices :";
	cin>>n;
	Graph g(n); // create a graph with n vertices
	for(int i=0;i<n;i++){
		cout<<"Enter the adjacent vertices of vertex :"<<i<<" (-1 to stop):\n";
		while(1){
			cin>>adj_vertex;
			if(adj_vertex == -1) break;
			g.addEdge(i,adj_vertex);
		}//end
	}//end

	if(g.isCyclic()) 
		cout << "Graph contains cycle\n"; 
	else
		cout << "Graph doesn't contain cycle\n"; 
	return 0; 
} 
/*
OUTPUT :
Enter number of vertices :4
Enter the adjacent vertices of vertex :0 (-1 to stop):
1 2 -1
Enter the adjacent vertices of vertex :1 (-1 to stop):
2 -1
Enter the adjacent vertices of vertex :2 (-1 to stop):
0 3 -1
Enter the adjacent vertices of vertex :3 (-1 to stop):
3 -1
Graph contains cycle
*/

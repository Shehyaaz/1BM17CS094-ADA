/*
Question 9b : Prim's Algorithm to find minimum cost spanning tree.
*/

#include <iostream>
#include <climits>
using namespace std;

void prims(int **cost, int n){
	int n_edges = 0;
	int mincost = 0;
	int min, u, v;
	int *elec = new int[n];
	for(int i = 0; i<n; i++) 
		elec[i]=1;
	while(n_edges != n-1){
		 min =  INT_MAX;
		 for(int i = 0; i<n; i++)
		 	for(int j = 0; j<n; j++)
		 		if(elec[i])
		 			if(cost[i][j] < min){
		 				min = cost[i][j];
		 				u = i;
		 				v = j;
		 			}//end of if
		 //end of for
		 if(elec[v]!=1){
		 	cout<<"u :"<<u<<"v :"<<v<<"min :"<<min<<endl;
		 	elec[v] = 1;
		 	n_edges = n_edges+1;
		 	mincost = mincost+min;
		 }//end of if
		 cost[u][v] = INT_MAX;
		 cost[v][u] = INT_MAX;
	}//end of loop
	cout<<"Min Cost : "<<mincost;
}//end of method

int main(){
	int **cost, n;
	cout<<"Enter number of vertices :";
	cin>>n;
	cost = new int*[n];
	for(int i =0; i<n; i++) cost[i] = new int[n];
	
	cout<<"Enter cost matrix :\n";
	for(int i =0; i<n ;i++)
		for(int j=0;j<n;j++)
			cin>>cost[i][j];
	prims(cost,n);
	return 0;
}//end of main

/*
OUPUT:
*/

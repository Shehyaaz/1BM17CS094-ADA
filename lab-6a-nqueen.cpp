// this program solves the N Queen problem using backtracking
#include <iostream>
#include <cmath>
using namespace std;

bool place(int *x, int k, int i){
	for(int j=1;j<k;j++){
		if((x[j] == i) || (abs(x[j]-i) == abs(j-k))) // in the same column or diagonal
			return false;	
	}
	return true;
}

void nQueens(int *x, int k, int n){
	for(int i=1; i<=n; i++){
		if(place(x,k,i)){
			x[k]=i;
			if(k==n){
				for(int l=1;l<=n;l++)
					cout<<x[l]<<"\t";
				cout<<"\n";
			}
			else
				nQueens(x,k+1,n);
		}
	}
}

int main(){
	int n;
	cout<<"Enter the number of queens :";
	cin>>n;
	if(n<4){
		cout<<"No solution exists";
		return 0;	
	}
	int *x = new int[n+1];
	nQueens(x,1,n);
	return 0;
}

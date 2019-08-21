#include <iostream>
using namespace std;

void smallestElements(int A[], int n, int k){
	int i,j,temp, min;
	for(i=0;i<k;i++){ // using Selection Sort
		min=i;
		for(j=i+1;j<n;j++){
			if(A[j]<A[min]) min = j;
		}
		temp  =A[i];
		A[i] = A[min];
		A[min]=temp;
	}
	cout<<k<<" th smallest element is :"<<A[k-1]<<"\n";
}

int main()
{
	int *A, n, k;
	cout<<"Enter number of elements :";
	cin>>n;
	A = new int[n];
	for(int i=0;i<n;i++){
		cout<<"Enter element :";
		cin>>A[i];
	}
	cout<<"Enter k :";
	cin>>k;
	smallestElements(A,n,k);
	return 0;
}
